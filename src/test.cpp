//
// Created by damtev on 30.07.2020.
//

#undef NDEBUG

#include <string>
#include <fstream>
#include <filesystem>
#include "table/table.hpp"
#include "exceptions/parsing/parsing_exception.hpp"
#include "exceptions/evaluation/evaluation_exception.hpp"
#include <cassert>
#include <iostream>

enum class ResultType {
  kCorrect,
  kParsingException,
  kEvaluationException
};

const std::string correct_answers_dir = "tests/correct/answers/";

std::unordered_map<std::string, ResultType> tests(
    {
        {"tests/correct/example.csv", ResultType::kCorrect},
        {"tests/correct/complex.csv", ResultType::kCorrect},
        {"tests/incorrect/evaluation/division_by_zero.csv", ResultType::kEvaluationException},
        {"tests/incorrect/evaluation/recursive_cell.csv", ResultType::kEvaluationException},
        {"tests/incorrect/parsing/non_unique_column_id.csv", ResultType::kParsingException},
        {"tests/incorrect/parsing/non_unique_row_id.csv", ResultType::kParsingException},
        {"tests/incorrect/parsing/unknown_cell.csv", ResultType::kParsingException},
        {"tests/incorrect/parsing/wrong_extension.txt", ResultType::kParsingException},
        {"tests/incorrect/parsing/wrong_cell_format.csv", ResultType::kParsingException}
    }
);

void Test() {
  for (const auto&[path_string, result_type] : tests) {
    Table table;
    try {
      Table::Parse(path_string, table);
      std::string table_string = (std::string) table;
      std::ifstream answer_stream(correct_answers_dir + std::filesystem::path(path_string).filename().string());
      std::string correct_answer((std::istreambuf_iterator<char>(answer_stream)),
                                 std::istreambuf_iterator<char>());
      assert(table_string == correct_answer);
    } catch (const ParsingException &parsing_exception) {
      assert(result_type == ResultType::kParsingException);
    } catch (const EvaluationException &evaluation_exception) {
      assert(result_type == ResultType::kEvaluationException);
    } catch (std::exception &exception) {
      assert(false);
    }
  }
}

int main() {
  Test();

  return 0;
}