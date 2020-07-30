//
// Created by damtev on 29.07.2020.
//

#pragma once

#include "parsing_exception.hpp"
#include "../../table/global_constants.hpp"

enum class TablePlaceType {
  kLine,
  kCell
};

class InvalidFormatException final : public ParsingException {
 private:
  const std::string explanation;
 public:
  InvalidFormatException(const std::filesystem::path &path, const std::string &line, const TablePlaceType &place_type)
      : ParsingException(path),
        explanation(
            (place_type == TablePlaceType::kLine ? "Line " + line + kLineSeparator() : "Cell " + line) + " at CSV file "
                + path.string() + " has invalid format") {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};