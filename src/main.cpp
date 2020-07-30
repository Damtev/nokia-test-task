//
// Created by damtev on 29.07.2020.
//

#include <iostream>
#include "table/table.hpp"
#include "exceptions/parsing/parsing_exception.hpp"
#include "exceptions/evaluation/evaluation_exception.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Expected at least 1 argument - path to CSV file" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; ++i) {
    Table table;
    try {
      Table::Parse(argv[i], table);
      std::cout << table << std::endl;
    } catch (const ParsingException &parsing_exception) {
      std::cerr << "[Parsing error]: " << parsing_exception.what() << std::endl;
    } catch (const EvaluationException &evaluation_exception) {
      std::cerr << "[Evaluation error]: " << evaluation_exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cerr << "[Runtime error]: " << exception.what() << std::endl;
    }
  }

  return 0;
}