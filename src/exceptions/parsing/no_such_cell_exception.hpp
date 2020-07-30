//
// Created by damtev on 29.07.2020.
//

#pragma once

#include "parsing_exception.hpp"
#include "../../table/global_constants.hpp"
#include "../../table/table.hpp"

class NoSuchCellException final : public ParsingException {
 private:
  const std::string explanation;
 public:
  NoSuchCellException(const std::filesystem::path &path,
                      const std::string cell_value_string,
                      const TablePosition &position)
      : ParsingException(path),
        explanation(
            "No such cell " + ((std::string) position) + " used in expression " + cell_value_string + " at CSV file "
                + path.string()) {}

  const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return explanation.c_str();
  }
};