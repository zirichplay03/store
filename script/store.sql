-- Таблица клиентов (пользователей)
CREATE TABLE IF NOT EXISTS users (
                                     id INTEGER PRIMARY KEY AUTOINCREMENT,
                                     login TEXT UNIQUE NOT NULL,
                                     password TEXT NOT NULL,
                                     full_name TEXT,
                                     role TEXT DEFAULT 'client'  -- добавляем роль
);

-- Таблица тренеров
CREATE TABLE IF NOT EXISTS trainers (
                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                        login TEXT UNIQUE NOT NULL,
                                        password TEXT NOT NULL,
                                        full_name TEXT NOT NULL,
                                        role TEXT DEFAULT 'trainer'  -- добавляем роль
);

-- Таблица контактов
CREATE TABLE IF NOT EXISTS contacts (
                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                        phone TEXT NOT NULL,
                                        email TEXT
);

-- Таблица цен
CREATE TABLE IF NOT EXISTS prices (
                                      id INTEGER PRIMARY KEY AUTOINCREMENT,
                                      price TEXT NOT NULL
);

-- Таблица услуг
CREATE TABLE IF NOT EXISTS services (
                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                        name TEXT NOT NULL,
                                        trainer_id INTEGER,
                                        contact_id INTEGER,
                                        price_id INTEGER,
                                        FOREIGN KEY (trainer_id) REFERENCES trainers(id),
                                        FOREIGN KEY (contact_id) REFERENCES contacts(id),
                                        FOREIGN KEY (price_id) REFERENCES prices(id)
);

-- Таблица расписания для тренеров
CREATE TABLE IF NOT EXISTS schedule (
                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                        trainer_id INTEGER,
                                        time_slot TEXT,  -- Время (например, '11:00-12:00')
                                        FOREIGN KEY (trainer_id) REFERENCES trainers(id)
);

-- Таблица записей на тренировки с именами клиентов и тренеров
CREATE TABLE IF NOT EXISTS bookings (
                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                        client_name TEXT NOT NULL,  -- Имя клиента
                                        trainer_name TEXT NOT NULL,  -- Имя тренера
                                        training_time TEXT NOT NULL  -- Время тренировки
);


-- Заполнение таблицы тренеров
INSERT INTO trainers (login, password, full_name) VALUES
                                                      ('trainer_olga', '123', 'Иванова Ольга'),
                                                      ('trainer_sergey', '123', 'Петров Сергей'),
                                                      ('trainer_dmitry', '123', 'Сидоров Дмитрий');

-- Заполнение таблицы контактов
INSERT INTO contacts (phone, email) VALUES
                                        ('+7 900 123-45-67', 'yoga@runhall.ru'),
                                        ('+7 901 456-78-90', 'ft@runhall.ru'),
                                        ('+7 902 333-44-55', 'personal@runhall.ru');

-- Заполнение таблицы цен
INSERT INTO prices (price) VALUES
                               ('1500 руб'),
                               ('2000 руб'),
                               ('2500 руб');

-- Заполнение таблицы услуг
INSERT INTO services (name, trainer_id, contact_id, price_id) VALUES
                                                                  ('Йога', 1, 1, 1),
                                                                  ('Функциональный тренинг', 2, 2, 2),
                                                                  ('Персональная тренировка', 3, 3, 3);

-- Заполнение таблицы клиентов
INSERT INTO users (login, password, full_name) VALUES
                                                   ('client_ivan', '123', 'Иван Иванов'),
                                                   ('client_maria', '123', 'Мария Кузнецова'),
                                                   ('client_egor', '123', 'Егор Смирнов');

-- Заполнение таблицы расписания тренеров
INSERT INTO schedule (trainer_id, time_slot) VALUES
                                                 (1, '11:00-12:00'),
                                                 (1, '14:00-15:00'),
                                                 (2, '10:00-11:00'),
                                                 (2, '15:00-16:00'),
                                                 (3, '12:00-13:00'),
                                                 (3, '16:00-17:00');
