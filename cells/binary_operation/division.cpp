//
// Created by damtev on 28.07.2020.
//

#include "division.hpp"
#include "../../exceptions/evaluation/division_by_zero_exception.hpp"

using namespace cell;
using namespace cell::binary_operation;

long long int Division::Operation(long long int first_value, long long int second_value) {
  if (second_value == 0) {
    throw DivisionByZeroException(this);
  }

  return first_value / second_value;
}