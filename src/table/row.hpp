//
// Created by damtev on 28.07.2020.
//

#pragma once

#include <unordered_map>
#include <vector>
#include "../../src/cells/cell.hpp"
#include "../global_constants.hpp"

struct Row {
  std::unordered_map<std::string, cell::Cell *> cells_;
  std::vector<std::string> column_ids_;

  explicit operator std::string();

  virtual ~Row();
};