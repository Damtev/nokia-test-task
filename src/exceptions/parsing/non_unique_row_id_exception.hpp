//
// Created by damtev on 30.07.2020.
//

#pragma once

#include "non_unique_id_exception.hpp"

class NonUniqueRowIdException final : public NonUniqueIdException {
 private:
  const std::string explanation;
 public:
  NonUniqueRowIdException(const std::filesystem::path &path, const size_t row_id)
      : NonUniqueIdException(path), explanation("Row id " + std::to_string(row_id) + this->NonUniqueIdException::explanation) {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};