cmake_minimum_required(VERSION 3.10)
project(API)

# Подключение библиотеки Abseil
find_package(absl REQUIRED)
# Убедитесь, что gRPC и Protobuf правильно найдены
find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)
find_package(SQLite3 REQUIRED)

# Указываем путь к заголовочным файлам protobuf
include_directories(
        ${ABSL_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include  # Добавление директории include
        ${CMAKE_SOURCE_DIR}/protos  # Добавление директории с protobuf исходниками
        ${PROTOBUF_INCLUDE_DIR}
        ${SQLite3_INCLUDE_DIRS}
)

# Сгенерированные файлы
set(hw_proto_srcs "${CMAKE_SOURCE_DIR}/protos/store.pb.cc")
set(hw_grpc_srcs "${CMAKE_SOURCE_DIR}/protos/store.grpc.pb.cc")

# hw_grpc_proto
add_library(hw_grpc_proto
        ${hw_grpc_srcs}
        ${hw_grpc_hdrs}
        ${hw_proto_srcs}
        ${hw_proto_hdrs})
target_link_libraries(hw_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
)

# Targets greeter_(client|server)
foreach(_target
        server_api)
    add_executable(${_target} "${_target}.cc")

    # Линковка с библиотеками
    target_link_libraries(${_target}
            hw_grpc_proto
            gRPC::grpc
            gRPC::grpc++
            protobuf::libprotobuf
            absl::strings
            absl::base
            absl::flags
            absl::time
            absl::flags_internal
            ${SQLite3_LIBRARIES}  # Линкуем с SQLite
    )
endforeach()

# Добавление зависимостей для сервера
target_link_libraries(server_api pthread)

# Путь к SQL-скрипту
set(SQL_SCRIPT "${CMAKE_SOURCE_DIR}/script/store.sql")

# Путь к создаваемой базе данных
set(DB_FILE "${CMAKE_BINARY_DIR}/store.db")

# Проверка наличия утилиты sqlite3
find_program(SQLITE3_EXECUTABLE sqlite3)

if(NOT SQLITE3_EXECUTABLE)
    message(FATAL_ERROR "sqlite3 is not installed on your system!")
endif()

# Выполнение SQL-скрипта после сборки сервера
add_custom_command(
        TARGET server_api POST_BUILD
        COMMAND ${SQLITE3_EXECUTABLE} ${DB_FILE} < ${SQL_SCRIPT}
        COMMENT "Creating database and tables...."
)

# Передаем путь к базе данных как макрос в исходный код
add_definitions(-DDB_PATH="${DB_FILE}")
