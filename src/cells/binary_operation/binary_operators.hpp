//
// Created by damtev on 29.07.2020.
//

#pragma once

#include <string>

namespace cell::binary_operation {

 enum class BinaryOperator {
   kAdditionOperator,
   kSubtractionOperator,
   kMultiplicationOperator,
   kDivisionOperator
 };
}

static cell::binary_operation::BinaryOperator FromString(const char binary_operator) {
  using namespace cell::binary_operation;
  switch (binary_operator) {
    case '+':
      return BinaryOperator::kAdditionOperator;
    case '-':
      return BinaryOperator::kSubtractionOperator;
    case '*':
      return BinaryOperator::kMultiplicationOperator;
    case '/':
      return BinaryOperator::kDivisionOperator;
    default:
      throw -1;
  }
}