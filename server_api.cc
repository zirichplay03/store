#include <grpcpp/grpcpp.h>
#include "store.grpc.pb.h"
#include "store.pb.h"
#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>
#include <sqlite3.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using store::AuthRequest;
using store::AuthResponse;
using store::RegisterRequest;
using store::RegisterResponse;
using store::ProductRequest;
using store::ProductResponse;
using store::AddToCartRequest;
using store::AddToCartResponse;
using store::CheckoutRequest;
using store::CheckoutResponse;
using store::StoreService;

// Структура для хранения данных пользователей
std::unordered_map<std::string, std::string> users; // {username: password}
std::unordered_map<int32_t, store::ProductResponse> products; // {product_id: product}

sqlite3* db;  // Указатель на базу данных

// Функция для открытия базы данных
bool OpenDatabase() {
    int rc = sqlite3_open(DB_PATH, &db);  // Используем путь, переданный через макрос
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

// Функция для закрытия базы данных
void CloseDatabase() {
    sqlite3_close(db);
}

// Пример функции для получения user_id из токена
int32_t GetUserIdFromToken(const std::string& token) {
    try {
        return std::stoi(token);  // Токен предполагается как строковое представление числа
    } catch (const std::exception& e) {
        return -1;  // Возвращаем -1, если токен некорректен
    }
}

class StoreServiceImpl final : public StoreService::Service {
public:
    // Реализация аутентификации
    Status Authenticate(ServerContext* context, const AuthRequest* request, AuthResponse* response) override {
        // Пример: Проверка данных в базе
        std::string sql = "SELECT password FROM users WHERE username = '" + request->username() + "';";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            response->set_message("Failed to query database");
            return Status(grpc::StatusCode::INTERNAL, "Database query failed");
        }

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const char* db_password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            if (db_password && request->password() == db_password) {
                response->set_token("dummy_token");  // Возвращаем фейковый токен
                response->set_message("Authentication successful");
                sqlite3_finalize(stmt);
                return Status::OK;
            }
        }
        response->set_message("Authentication failed");
        sqlite3_finalize(stmt);
        return Status(grpc::StatusCode::UNAUTHENTICATED, "Invalid credentials");
    }

    // Реализация регистрации пользователя
    Status RegisterUser(ServerContext* context, const RegisterRequest* request, RegisterResponse* response) override {
        // Пример: Добавление пользователя в базу данных
        std::string sql = "INSERT INTO users (username, password, email) VALUES ('" + request->username() + "', '" + request->password() + "', '" + request->email() + "');";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            response->set_success(false);
            response->set_message("Failed to insert user into database");
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            response->set_success(false);
            response->set_message("Failed to insert user into database");
            sqlite3_finalize(stmt);
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        response->set_success(true);
        response->set_message("Registration successful");
        sqlite3_finalize(stmt);
        return Status::OK;
    }

    // Получение информации о товаре
    Status GetProduct(ServerContext* context, const ProductRequest* request, ProductResponse* response) override {
        std::string sql = "SELECT name, description, price, stock FROM products WHERE id = " + std::to_string(request->product_id()) + ";";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            return Status(grpc::StatusCode::INTERNAL, "Database query failed");
        }

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            response->set_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            response->set_description(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            response->set_price(sqlite3_column_double(stmt, 2));
            response->set_stock(sqlite3_column_int(stmt, 3));
            sqlite3_finalize(stmt);
            return Status::OK;
        }
        sqlite3_finalize(stmt);
        return Status(grpc::StatusCode::NOT_FOUND, "Product not found");
    }

    // Добавление товара в корзину
    Status AddToCart(ServerContext* context, const AddToCartRequest* request, AddToCartResponse* response) override {
        // Получаем user_id из токена
        int32_t user_id = GetUserIdFromToken(request->token());
        if (user_id == -1) {
            response->set_message("Invalid token");
            response->set_success(false);
            return Status(grpc::StatusCode::UNAUTHENTICATED, "Invalid token");
        }

        std::string sql = "INSERT INTO carts (user_id, product_id, quantity) VALUES (" +
                          std::to_string(user_id) + ", " +
                          std::to_string(request->product_id()) + ", " +
                          std::to_string(request->quantity()) + ");";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            response->set_message("Failed to add product to cart");
            response->set_success(false);
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            response->set_message("Failed to add product to cart");
            response->set_success(false);
            sqlite3_finalize(stmt);
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        response->set_message("Product added to cart");
        response->set_success(true);
        sqlite3_finalize(stmt);
        return Status::OK;
    }

    // Оформление заказа
    Status Checkout(ServerContext* context, const CheckoutRequest* request, CheckoutResponse* response) override {
        // Получаем user_id из токена
        int32_t user_id = GetUserIdFromToken(request->token());
        if (user_id == -1) {
            response->set_message("Invalid token");
            return Status(grpc::StatusCode::UNAUTHENTICATED, "Invalid token");
        }

        std::string sql = "INSERT INTO orders (user_id, total_price) VALUES (" + std::to_string(user_id) + ", 100.50);";
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) != SQLITE_OK) {
            response->set_message("Failed to create order");
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            response->set_message("Failed to create order");
            sqlite3_finalize(stmt);
            return Status(grpc::StatusCode::INTERNAL, "Database insert failed");
        }
        response->set_order_id("order_12345");
        response->set_total_price(100.50);
        response->set_message("Order successfully placed");
        sqlite3_finalize(stmt);
        return Status::OK;
    }
};

void RunServer(uint16_t port) {
    if (!OpenDatabase()) {
        std::cerr << "Database connection failed!" << std::endl;
        return;
    }

    std::string server_address = "0.0.0.0:" + std::to_string(port);
    StoreServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();

    CloseDatabase();  // Закрываем базу данных перед завершением
}

int main(int argc, char** argv) {
    uint16_t port = 50051;  // По умолчанию порт 50051
    RunServer(port);
    return 0;
}
