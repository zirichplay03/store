-- Создание таблицы пользователей
CREATE TABLE IF NOT EXISTS users (
id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     username TEXT NOT NULL UNIQUE,
                                     password TEXT NOT NULL,
                                     email TEXT NOT NULL UNIQUE,
                                     role TEXT CHECK(role IN ('buyer', 'seller')) NOT NULL,  -- Роль пользователя
                                     created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Создание таблицы заказов
CREATE TABLE IF NOT EXISTS orders (
                                      id INTEGER PRIMARY KEY AUTOINCREMENT,
                                      user_id INTEGER NOT NULL, -- Идентификатор покупателя
                                      total_price REAL NOT NULL,
                                      status TEXT DEFAULT 'pending', -- Статус заказа: pending, confirmed, declined
                                      created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
                                      FOREIGN KEY (user_id) REFERENCES users(id)
);


-- Создание таблицы товаров, если она еще не существует
CREATE TABLE IF NOT EXISTS products (
id INTEGER PRIMARY KEY AUTOINCREMENT,
name TEXT NOT NULL,
description TEXT,
price REAL NOT NULL,
stock INTEGER NOT NULL,
created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- Создание таблицы корзин (каждый пользователь может иметь свою корзину), если она еще не существует
CREATE TABLE IF NOT EXISTS carts (
id INTEGER PRIMARY KEY AUTOINCREMENT,
user_id INTEGER NOT NULL,
product_id INTEGER NOT NULL,
quantity INTEGER NOT NULL,
added_at DATETIME DEFAULT CURRENT_TIMESTAMP,
FOREIGN KEY (user_id) REFERENCES users(id),
FOREIGN KEY (product_id) REFERENCES products(id)
);

-- Создание таблицы для товаров в заказах, если она еще не существует
CREATE TABLE IF NOT EXISTS order_items (
id INTEGER PRIMARY KEY AUTOINCREMENT,
order_id INTEGER NOT NULL,
product_id INTEGER NOT NULL,
quantity INTEGER NOT NULL,
price REAL NOT NULL,
FOREIGN KEY (order_id) REFERENCES orders(id),
FOREIGN KEY (product_id) REFERENCES products(id)
);
