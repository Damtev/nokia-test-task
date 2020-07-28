//
// Created by damtev on 28.07.2020.
//

#pragma once

#include <unordered_map>
#include <vector>
#include "../../src/cells/cell.hpp"

class Row {
 private:
  std::unordered_map<std::string, cell::Cell *> cells_;
  std::vector<std::string> column_ids;

 public:
  explicit operator std::string() {
    std::string string_row;
    std::string separator;
    for (const std::string &column_id : column_ids) {
      string_row += separator;
      string_row += std::to_string(cells_[column_id]->Evaluate());
      separator = ",";
    }
    string_row += "\r\n";

    return string_row;
  }
};
