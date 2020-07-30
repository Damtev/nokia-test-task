//
// Created by damtev on 29.07.2020.
//

#include "binary_operation.hpp"
#include "binary_operators.hpp"
#include "addition.hpp"
#include "multiplication.hpp"
#include "division.hpp"
#include "subtraction.hpp"

using namespace cell::binary_operation;

namespace cell::binary_operation {

 static BinaryOperation *MakeBinaryOperation(std::string_view column_id,
                                             size_t row_id,
                                             const char binary_operator_char) {
   BinaryOperator binary_operator = FromString(binary_operator_char);
   switch (binary_operator) {
     case BinaryOperator::kAdditionOperator:
       return new Addition(column_id, row_id);
     case BinaryOperator::kSubtractionOperator:
       return new Subtraction(column_id, row_id);
     case BinaryOperator::kMultiplicationOperator:
       return new Multiplication(column_id, row_id);
     case BinaryOperator::kDivisionOperator:
       return new Division(column_id, row_id);
     default:
       throw std::runtime_error("Unknown binary operator");
   }
 }
}