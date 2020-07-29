//
// Created by damtev on 29.07.2020.
//

#pragma once

#include "parsing_exception.hpp"

class NoSuchPathException final : public ParsingException {
 private:
  const std::string explanation;
 public:
  NoSuchPathException(const std::filesystem::path &path)
      : ParsingException(path), explanation("Path " + path.string() + " does not exist") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};