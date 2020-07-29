//
// Created by damtev on 28.07.2020.
//

#include "const.hpp"

using namespace cell::unary_operation;

Const::Const(std::string_view column_id, const size_t row_id) : Cell(column_id, row_id) {
  state_ = EvaluationState::kEvaluated;
}

Const::Const(std::string_view column_id, const size_t row_id, long long int value) : Const(column_id, row_id) {
  value_ = value;
}

long long int Const::GetValue() const {
  return value_;
}

void Const::SetValue(long long int value) {
  value_ = value;
}

long long int Const::Evaluate() {
  if (evaluated_value.has_value()) {
    return evaluated_value.value();
  }

  evaluated_value = value_;
  return value_;
}