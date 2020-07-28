//
// Created by damtev on 28.07.2020.
//

#pragma once

#include "evaluation_exception.hpp"

class RecursionException final : public EvaluationException {
 private:
  const std::string explanation;
 public:
  RecursionException(cell::Cell *cell)
      : EvaluationException(cell), explanation("Cell " + cell->GetPosition() + " has recursive definition") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};