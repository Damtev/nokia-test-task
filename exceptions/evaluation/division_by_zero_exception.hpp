//
// Created by damtev on 28.07.2020.
//

#pragma once

#include "evaluation_exception.hpp"
#include "../../cells/binary_operation/division.hpp"

using namespace cell::binary_operation;

class DivisionByZeroException final : public EvaluationException {
 private:
  const std::string explanation;
 public:
  DivisionByZeroException(Division *division_cell)
      : EvaluationException(division_cell), explanation("Value at cell " + division_cell->GetPosition() + " is divided by zero") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};