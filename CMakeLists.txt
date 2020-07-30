cmake_minimum_required(VERSION 3.17)
project(test_task)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES_DIR src/)
set(CELL_SOURCES_DIR ${SOURCES_DIR}cells/)
set(CELL_UNARY_SOURCES_DIR ${CELL_SOURCES_DIR}unary_operation/)
set(CELL_BINARY_SOURCES_DIR ${CELL_SOURCES_DIR}binary_operation/)
set(TABLE_SOURCES_DIR ${SOURCES_DIR}table/)
set(EXCEPTION_SOURCES_DIR ${SOURCES_DIR}exceptions/)
set(EVALUATION_EXCEPTION_SOURCES_DIR ${EXCEPTION_SOURCES_DIR}evaluation/)
set(PARSING_EXCEPTION_SOURCES_DIR ${EXCEPTION_SOURCES_DIR}parsing/)

add_library(table_processor STATIC
        ${SOURCES_DIR}global_constants.hpp

        ${CELL_SOURCES_DIR}cell.hpp
        ${CELL_SOURCES_DIR}cell.cpp
        ${CELL_SOURCES_DIR}evaluation_state.hpp

        ${CELL_UNARY_SOURCES_DIR}const.hpp
        ${CELL_UNARY_SOURCES_DIR}const.cpp

        ${CELL_BINARY_SOURCES_DIR}binary_operation.hpp
        ${CELL_BINARY_SOURCES_DIR}binary_operation.cpp
        ${CELL_BINARY_SOURCES_DIR}addition.cpp
        ${CELL_BINARY_SOURCES_DIR}addition.hpp
        ${CELL_BINARY_SOURCES_DIR}subtraction.cpp
        ${CELL_BINARY_SOURCES_DIR}subtraction.hpp
        ${CELL_BINARY_SOURCES_DIR}division.cpp
        ${CELL_BINARY_SOURCES_DIR}division.hpp
        ${CELL_BINARY_SOURCES_DIR}multiplication.cpp
        ${CELL_BINARY_SOURCES_DIR}multiplication.hpp
        ${CELL_BINARY_SOURCES_DIR}binary_operation_factory.hpp
        ${CELL_BINARY_SOURCES_DIR}binary_operators.hpp

        ${TABLE_SOURCES_DIR}row.hpp
        ${TABLE_SOURCES_DIR}table.cpp
        ${TABLE_SOURCES_DIR}table.hpp
        ${TABLE_SOURCES_DIR}row.cpp

        ${EVALUATION_EXCEPTION_SOURCES_DIR}recursion_exception.hpp
        ${EVALUATION_EXCEPTION_SOURCES_DIR}evaluation_exception.hpp
        ${EVALUATION_EXCEPTION_SOURCES_DIR}division_by_zero_exception.hpp

        ${PARSING_EXCEPTION_SOURCES_DIR}parsing_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}not_csv_file_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}no_such_path_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}invalid_format_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}no_such_cell_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}non_unique_id_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}non_unique_column_id_exception.hpp
        ${PARSING_EXCEPTION_SOURCES_DIR}non_unique_row_id_exception.hpp)

set(SOURCE_EXE ${SOURCES_DIR}main.cpp)
set(TEST_EXE ${SOURCES_DIR}test.cpp)

add_executable(test_task_main ${SOURCE_EXE})
add_executable(test_task_test ${TEST_EXE})

target_link_libraries(test_task_main table_processor)
target_link_libraries(test_task_test table_processor)