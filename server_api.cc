#include "store.grpc.pb.h"
#include <iostream>
#include <sqlite3.h>
#include <grpcpp/grpcpp.h>
#include <string>
#include <unordered_map>

class FitnessServiceImpl final : public fitness::FitnessService::Service {
public:
    FitnessServiceImpl();
    ~FitnessServiceImpl();

    grpc::Status GetServices(grpc::ServerContext* context, const fitness::Empty* request, fitness::ServiceList* response) override;
    grpc::Status LoginUser(grpc::ServerContext* context, const fitness::LoginRequest* request, fitness::LoginResponse* response) override;
    grpc::Status RegisterUser(grpc::ServerContext* context, const fitness::RegisterRequest* request, fitness::RegisterResponse* response) override;
    grpc::Status GetTrainers(grpc::ServerContext* context, const fitness::Empty* request, fitness::TrainerList* response) override;
    grpc::Status GetTrainerSchedule(grpc::ServerContext* context, const fitness::TrainerScheduleRequest* request, fitness::TrainerScheduleResponse* response) override;
    grpc::Status GetTrainerClients(grpc::ServerContext* context, const fitness::TrainerClientsRequest* request, fitness::TrainerClientsResponse* response) override;
    grpc::Status GetContacts(grpc::ServerContext* context, const fitness::Empty* request, fitness::ContactList* response) override;
    grpc::Status GetPrices(grpc::ServerContext* context, const fitness::Empty* request, fitness::PriceList* response) override;
    grpc::Status BookTraining(grpc::ServerContext* context, const fitness::TrainingBookingRequest* request, fitness::TrainingBookingResponse* response) override;
    grpc::Status AddBalance(grpc::ServerContext* context, const fitness::BalanceRequest* request, fitness::BalanceResponse* response) override;

private:
    sqlite3* db_;
    std::unordered_map<std::string, float> balances_;  // Баланс клиентов
    void openDatabase();
};

FitnessServiceImpl::FitnessServiceImpl() {
    openDatabase();
}

FitnessServiceImpl::~FitnessServiceImpl() {
    sqlite3_close(db_);
}

void FitnessServiceImpl::openDatabase() {
    const char* dbPath = DB_PATH;  // Путь к вашей базе данных
    if (sqlite3_open(dbPath, &db_) != SQLITE_OK) {
        std::cerr << "Ошибка подключения к базе данных: " << sqlite3_errmsg(db_) << std::endl;
        exit(1);
    }
}

// Обработка запроса на услуги
grpc::Status FitnessServiceImpl::GetServices(grpc::ServerContext*, const fitness::Empty*, fitness::ServiceList* response) {
    const char* sql = R"(
        SELECT s.name, p.price, t.full_name, c.phone || ' / ' || COALESCE(c.email, '')
        FROM services s
        JOIN trainers t ON s.trainer_id = t.id
        JOIN prices p ON s.price_id = p.id
        JOIN contacts c ON s.contact_id = c.id
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto* service = response->add_services();
        service->set_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        service->set_price(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        service->set_trainer(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        service->set_contact(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}

grpc::Status FitnessServiceImpl::GetContacts(grpc::ServerContext*, const fitness::Empty*, fitness::ContactList* response) {
    const char* sql = R"(
        SELECT phone, email FROM contacts
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto* contact = response->add_contacts();
        contact->set_phone(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        contact->set_email(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}

grpc::Status FitnessServiceImpl::GetTrainers(grpc::ServerContext*, const fitness::Empty*, fitness::TrainerList* response) {
    const char* sql = "SELECT full_name FROM trainers";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto* trainer = response->add_trainers();
        trainer->set_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}


grpc::Status FitnessServiceImpl::LoginUser(grpc::ServerContext*, const fitness::LoginRequest* request, fitness::LoginResponse* response) {
    const char* tables[] = {"users", "trainers"};
    const char* roles[] = {"client", "trainer"};

    for (int i = 0; i < 2; ++i) {
        std::string sql = "SELECT full_name FROM " + std::string(tables[i]) +
                          " WHERE login=? AND password=?";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
        }

        sqlite3_bind_text(stmt, 1, request->login().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, request->password().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            response->set_success(true);
            response->set_role(roles[i]);
            response->set_full_name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            sqlite3_finalize(stmt);
            return grpc::Status::OK;
        }
        sqlite3_finalize(stmt);
    }

    response->set_success(false);
    return grpc::Status::OK;
}

grpc::Status FitnessServiceImpl::GetPrices(grpc::ServerContext*, const fitness::Empty*, fitness::PriceList* response) {
    const char* sql = "SELECT price FROM prices";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto* price = response->add_prices();
        price->set_price(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}


// Логика регистрации
grpc::Status FitnessServiceImpl::RegisterUser(grpc::ServerContext*, const fitness::RegisterRequest* request, fitness::RegisterResponse* response) {
    const char* sql = "INSERT INTO users (login, password, full_name) VALUES (?, ?, ?)";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        response->set_success(false);
        response->set_message("Ошибка при добавлении в базу: " + std::string(sqlite3_errmsg(db_)));
        return grpc::Status::OK;
    }

    sqlite3_bind_text(stmt, 1, request->login().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, request->password().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, request->full_name().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        response->set_success(true);
        response->set_message("Регистрация успешна");
    } else {
        response->set_success(false);
        response->set_message("Ошибка при добавлении в базу: " + std::string(sqlite3_errmsg(db_)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}

// Получить расписание тренера
grpc::Status FitnessServiceImpl::GetTrainerSchedule(grpc::ServerContext* context, const fitness::TrainerScheduleRequest* request, fitness::TrainerScheduleResponse* response) {
    const char* sql = "SELECT time_slot FROM schedule WHERE trainer_id = (SELECT id FROM trainers WHERE full_name = ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    sqlite3_bind_text(stmt, 1, request->trainer_name().c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        response->add_schedule(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}

grpc::Status FitnessServiceImpl::GetTrainerClients(grpc::ServerContext* context, const fitness::TrainerClientsRequest* request, fitness::TrainerClientsResponse* response) {
    const char* sql = R"(
        SELECT u.full_name, b.training_time
        FROM bookings b
        JOIN users u ON b.client_id = u.id
        JOIN trainers t ON b.trainer_id = t.id
        WHERE t.login = ?
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return grpc::Status(grpc::StatusCode::INTERNAL, sqlite3_errmsg(db_));
    }

    sqlite3_bind_text(stmt, 1, request->trainer_name().c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string client_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string training_time = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

        auto* client_info = response->add_clients();
        client_info->set_client_name(client_name);
        client_info->set_training_time(training_time);
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}


// Метод для записи на тренировку
grpc::Status FitnessServiceImpl::BookTraining(grpc::ServerContext* context, const fitness::TrainingBookingRequest* request, fitness::TrainingBookingResponse* response) {
    const char* sql = "INSERT INTO bookings (trainer_id, client_id, training_time) VALUES ((SELECT id FROM trainers WHERE full_name = ?), (SELECT id FROM users WHERE full_name = ?), ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        response->set_success(false);
        response->set_message("Ошибка записи: " + std::string(sqlite3_errmsg(db_)));
        return grpc::Status::OK;
    }

    sqlite3_bind_text(stmt, 1, request->trainer_name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, request->client_name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, request->training_time().c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        response->set_success(true);
        response->set_message("Запись на тренировку успешна");
    } else {
        response->set_success(false);
        response->set_message("Ошибка при добавлении в базу: " + std::string(sqlite3_errmsg(db_)));
    }

    sqlite3_finalize(stmt);
    return grpc::Status::OK;
}

// Пополнение баланса клиента
grpc::Status FitnessServiceImpl::AddBalance(grpc::ServerContext* context, const fitness::BalanceRequest* request, fitness::BalanceResponse* response) {
    if (balances_.find(request->client_name()) == balances_.end()) {
        balances_[request->client_name()] = 0.0;
    }

    balances_[request->client_name()] += request->amount();
    response->set_success(true);
    response->set_new_balance(balances_[request->client_name()]);

    return grpc::Status::OK;
}

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    FitnessServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server running at " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();

    return 0;
}
