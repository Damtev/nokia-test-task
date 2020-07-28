//
// Created by damtev on 28.07.2020.
//

#pragma once

#include <exception>
#include "../../../cells/cell.hpp"

class EvaluationException : public std::exception {
 public:
  explicit EvaluationException(cell::Cell *cell) : cell_(cell) {}

  [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = 0;

 protected:
  cell::Cell *cell_;
};