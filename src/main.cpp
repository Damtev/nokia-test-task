//
// Created by damtev on 29.07.2020.
//

#include <iostream>
#include "table/table.hpp"

int main() {
  Table table;
  Table::Parse("tests/example.csv", table);
  std::cout << (std::string) table;

  return 0;
}