//
// Created by damtev on 30.07.2020.
//

#pragma once

#include "non_unique_id_exception.hpp"

class NonUniqueColumnIdException final : public NonUniqueIdException {
 private:
  const std::string explanation;
 public:
  NonUniqueColumnIdException(const std::filesystem::path &path, const std::string &column_id)
      : NonUniqueIdException(path), explanation("Column id " + column_id + this->NonUniqueIdException::explanation) {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};