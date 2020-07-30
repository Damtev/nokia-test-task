//
// Created by damtev on 30.07.2020.
//

#pragma once

#include "parsing_exception.hpp"

class NonUniqueIdException : public ParsingException {
 protected:
  const std::string explanation;
 public:
  NonUniqueIdException(const std::filesystem::path &path)
      : ParsingException(path), explanation(" is non-unique") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};