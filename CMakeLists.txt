cmake_minimum_required(VERSION 3.17)
project(test_task)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_task src/cells/cell.hpp src/cells/cell.cpp src/cells/unary_operation/const.hpp src/cells/unary_operation/const.cpp src/cells/evaluation_state.hpp src/cells/binary_operation/binary_operation.hpp src/cells/binary_operation/binary_operation.cpp src/cells/binary_operation/addition.cpp src/cells/binary_operation/addition.hpp src/exceptions/evaluation/recursion_exception.hpp src/exceptions/evaluation/evaluation_exception.hpp src/cells/binary_operation/subtraction.cpp src/cells/binary_operation/subtraction.hpp src/exceptions/evaluation/division_by_zero_exception.hpp src/cells/binary_operation/division.cpp src/cells/binary_operation/division.hpp src/cells/binary_operation/multiplication.cpp src/cells/binary_operation/multiplication.hpp src/table/row.hpp)