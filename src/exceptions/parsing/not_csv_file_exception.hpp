//
// Created by damtev on 29.07.2020.
//

#pragma once

#include "parsing_exception.hpp"

class NotCsvFileException final : public ParsingException {
 private:
  const std::string explanation;
 public:
  NotCsvFileException(const std::filesystem::path &path)
      : ParsingException(path), explanation("File " + path.string() + " is not CSV") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};