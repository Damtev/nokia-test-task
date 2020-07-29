//
// Created by damtev on 28.07.2020.
//

#include "table.hpp"
#include <filesystem>
#include <fstream>
#include "../exceptions/parsing/no_such_path_exception.hpp"
#include "../exceptions/parsing/not_csv_file_exception.hpp"
#include "../exceptions/parsing/invalid_format_exception.hpp"
#include "../exceptions/parsing/no_such_cell_exception.hpp"
#include "../cells/unary_operation/const.hpp"
#include "../cells/binary_operation/addition.hpp"
#include "../cells/binary_operation/subtraction.hpp"
#include "../cells/binary_operation/multiplication.hpp"
#include "../cells/binary_operation/division.hpp"
#include "../cells/binary_operation/binary_operation_factory.hpp"
#include <regex>
#include <unordered_set>

using namespace std::filesystem;
using namespace cell;
using namespace cell::unary_operation;
using namespace cell::binary_operation;

namespace std {
 template<>
 struct hash<TablePosition> {
  public:
   std::size_t operator()(TablePosition const &table_position) const noexcept {
     return std::hash<std::string>()(table_position.column_id) ^ std::hash<size_t>()(table_position.row_id);
   }
 };
};

void Table::Parse(const path &path, Table &table) {
  if (!exists(path)) {
    throw NoSuchPathException(path);
  }

  if (path.extension().string() != kCsvExtension) {
    throw NotCsvFileException(path);
  }

  std::ifstream file_stream(path);
//  try {
    ParseHeader(path, file_stream, table);
    ParseRows(path, file_stream, table);
//  } catch (const ParsingException &parsing_exception) {
//    file_stream.close();
//    throw parsing_exception;
//  }
}

void Table::ParseHeader(const path &path, std::ifstream &file_stream, Table &table) {
  std::string header;
  std::getline(file_stream, header);
  std::regex header_regex(kHeaderRegex);
  if (!std::regex_match(header, header_regex)) {
    throw InvalidFormatException(path, header);
  }

  std::istringstream header_splitter(header);
  std::string column_id;
  std::unordered_set<std::string> used_columns; // column ids should be unique
  std::getline(header_splitter, column_id, kCellsSeparator); // skip empty column_id
  while (std::getline(header_splitter, column_id, kCellsSeparator)) {
    if (used_columns.count(column_id) != 0) {
      throw InvalidFormatException(path, header);
    }

    used_columns.insert(column_id);
    table.column_ids_.push_back(column_id);
  }
}

void Table::ParseRows(const path &path, std::ifstream &file_stream, Table &table) {
  std::string row_string;
  std::unordered_set<size_t> used_rows; // row ids should be unique
  std::unordered_map<TablePosition, std::string> cell_value_strings;
  while (std::getline(file_stream, row_string)) {
    std::istringstream row_splitter(row_string);
    std::string row_id_string;
    std::getline(row_splitter, row_id_string, kCellsSeparator); // read row id
    std::stringstream row_id_stream(row_id_string);
    size_t row_id;
    row_id_stream >> row_id;
    if (used_rows.count(row_id) != 0) {
      throw InvalidFormatException(path, row_string);
    }
    used_rows.insert(row_id);
    table.row_ids_.push_back(row_id);

    std::string cell_value_string;
    size_t cur_column_number = 0;
    Row *row = new Row();
    table.rows_[row_id] = row;
    while (std::getline(row_splitter, cell_value_string, kCellsSeparator)) {
      std::string column_id = table.column_ids_[cur_column_number];
      std::regex cell_regex(kCellRegex);
      if (!std::regex_match(cell_value_string, cell_regex)) {
        throw InvalidFormatException(path, cell_value_string);
      }

      row->column_ids_.push_back(column_id);
      std::regex number_regex(kNumberRegex);
      if (std::regex_match(cell_value_string, number_regex)) {
        size_t cell_value;
        std::stringstream cell_value_stream(cell_value_string);
        cell_value_stream >> cell_value;
        row->cells_[column_id] = new Const(column_id, row_id, cell_value);
      } else {
        std::regex binary_operation_regex(kBinaryOperatorsRegex);
        std::smatch operator_match;
        std::regex_search(cell_value_string, operator_match, binary_operation_regex);
        char binary_operator = operator_match.str(0)[0];
        row->cells_[column_id] = MakeBinaryOperation(column_id, row_id, binary_operator);
      }

      TablePosition table_position(column_id, row_id);
      cell_value_strings[table_position] = cell_value_string;

      ++cur_column_number;
    }
  }

  SetCellOperands(path, table, cell_value_strings);
}

void Table::SetCellOperands(const std::filesystem::path &path,
                            Table &table,
                            const std::unordered_map<TablePosition, std::string> &cell_value_strings) {
  for (const size_t row_id : table.row_ids_) {
    Row *row = table.rows_[row_id];
    for (const std::string &column_id : row->column_ids_) {
      TablePosition cell_table_position(column_id, row_id);
      const std::string cell_value_string = cell_value_strings.at(cell_table_position);
      std::regex binary_operation_regex(kBinaryOperatorsRegex);
      std::smatch operator_match;
      if (!std::regex_search(cell_value_string, operator_match, binary_operation_regex)) {
        continue;
      }

      BinaryOperation *binary_operation = dynamic_cast<BinaryOperation *>(row->cells_[column_id]);
      std::string first_operand_string = operator_match.prefix().str().substr(1); // skip '='
      std::string second_operand_string = operator_match.suffix().str();

      binary_operation->SetFirstOperand(GetOperand(first_operand_string,
                                                   path,
                                                   table,
                                                   cell_value_string,
                                                   column_id,
                                                   row_id));
      binary_operation->SetSecondOperand(GetOperand(second_operand_string,
                                                    path,
                                                    table,
                                                    cell_value_string,
                                                    column_id,
                                                    row_id));
    }
  }
}

Cell *Table::GetOperand(const std::string operand_string,
                        const path &path,
                        Table &table,
                        const std::string &cell_value_string,
                        const std::string &column_id,
                        size_t row_id) {
  std::regex row_id_regex(kRowIdRegex);
  std::smatch first_operand_row_id_match;
  std::regex_search(operand_string, first_operand_row_id_match, row_id_regex);

  size_t first_operand_row_id;
  std::stringstream first_operand_row_id_stream(first_operand_row_id_match.str(0));
  first_operand_row_id_stream >> first_operand_row_id;
  const std::string &first_operand_column_id = first_operand_row_id_match.prefix();

  if (table.rows_.count(first_operand_row_id) == 0
      || (table.rows_[first_operand_row_id]->cells_.count(first_operand_column_id) == 0)) {
    throw NoSuchCellException(path, cell_value_string, TablePosition(column_id, row_id));
  }
  return table.rows_[first_operand_row_id]->cells_[first_operand_column_id];
}

std::string Table::ReturnHeader() const {
  std::string first_line = std::string(1, kCellsSeparator);
  std::string cells_separator;
  for (const std::string &column_id : column_ids_) {
    first_line += cells_separator;
    first_line += column_id;
    cells_separator = std::string(1, kCellsSeparator);
  }
  first_line += kLineSeparator();

  return first_line;
}

Table::operator std::string() {
  std::string string_table = ReturnHeader();

  std::string line_separator;
  for (const size_t row_id : row_ids_) {
    string_table += line_separator;
    string_table += std::to_string(row_id) + kCellsSeparator;
    string_table += rows_[row_id]->operator std::string();
    line_separator = kLineSeparator();
  }

  return string_table;
}

std::vector<std::string> &Table::GetColumnIds() {
  return column_ids_;
}

void Table::SetColumnIds(const std::vector<std::string> &column_ids) {
  column_ids_ = column_ids;
}

std::vector<size_t> &Table::GetRowIds() {
  return row_ids_;
}

void Table::SetRowIds(const std::vector<size_t> &row_ids) {
  row_ids_ = row_ids;
}

Table::~Table() {
  for (const size_t row_id : row_ids_) {
    delete rows_[row_id];
  }
}
