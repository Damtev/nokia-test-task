//
// Created by damtev on 29.07.2020.
//

#pragma once

#include "parsing_exception.hpp"
#include "../../table/global_constants.hpp"

class InvalidFormatException final : public ParsingException {
 private:
  const std::string explanation;
 public:
  InvalidFormatException(const std::filesystem::path &path, const std::string &line)
      : ParsingException(path), explanation("Line " + line + kLineSeparator() + " at CSV file " + path.string() + " has invalid format") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};