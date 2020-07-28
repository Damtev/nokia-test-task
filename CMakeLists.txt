cmake_minimum_required(VERSION 3.17)
project(test_task)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_task cells/cell.hpp cells/cell.cpp cells/unary_operation/const.hpp cells/unary_operation/const.cpp cells/evaluation_state.hpp cells/binary_operation/binary_operation.hpp cells/binary_operation/binary_operation.cpp cells/binary_operation/addition.cpp cells/binary_operation/addition.hpp exceptions/evaluation/recursion_exception.hpp exceptions/evaluation/evaluation_exception.hpp cells/binary_operation/subtraction.cpp cells/binary_operation/subtraction.hpp exceptions/evaluation/division_by_zero_exception.hpp cells/binary_operation/division.cpp cells/binary_operation/division.hpp cells/binary_operation/multiplication.cpp cells/binary_operation/multiplication.hpp table/row.hpp)