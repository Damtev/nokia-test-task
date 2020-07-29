//
// Created by damtev on 29.07.2020.
//

#include "row.hpp"

Row::operator std::string() {
  std::string string_row;
  std::string cells_separator;
  for (const std::string &column_id : column_ids_) {
    string_row += cells_separator;
    string_row += std::to_string(cells_[column_id]->Evaluate());
    cells_separator = kCellsSeparator;
  }

  return string_row;
}

Row::~Row() {
  for (const auto&[row_id, cell] : cells_) {
    delete cell;
  }
}
