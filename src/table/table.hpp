//
// Created by damtev on 28.07.2020.
//

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>
#include "row.hpp"
#include "global_constants.hpp"
#include "../cells/cell.hpp"

struct TablePosition {
  std::string column_id;
  size_t row_id;

  TablePosition(const std::string &column_id, size_t row_id) : column_id(column_id), row_id(row_id) {}

  bool operator==(const TablePosition &rhs) const {
    return column_id == rhs.column_id &&
        row_id == rhs.row_id;
  }

  bool operator!=(const TablePosition &rhs) const {
    return !(rhs == *this);
  }

  operator std::string() const {
    return column_id + std::to_string(row_id);
  }
};

class Table {
 private:
  std::vector<std::string> column_ids_;
  std::vector<size_t> row_ids_;
  std::unordered_map<size_t, Row*> rows_;

  std::string ReturnHeader() const;

  static void ParseHeader(const std::filesystem::path &path, std::ifstream &file_stream, Table &table);

  static void ParseRows(const std::filesystem::path &path, std::ifstream &file_stream, Table &table);

  static cell::Cell *GetOperand(const std::string operand_string,
                                const std::filesystem::path &path,
                                Table &table,
                                const std::string &cell_value_string,
                                const std::string &column_id,
                                size_t row_id);

  static void SetCellOperands(const std::filesystem::path &path,
                              Table &table,
                              const std::unordered_map<TablePosition, std::string> &cell_value_strings);

 public:
  Table() = default;

  ~Table();

  static void Parse(const std::filesystem::path &path, Table &table);

  explicit operator std::string();

  std::vector<std::string> &GetColumnIds();

  void SetColumnIds(const std::vector<std::string> &column_ids);

  std::vector<size_t> &GetRowIds();

  void SetRowIds(const std::vector<size_t> &row_ids);

  std::unordered_map<std::string, Row> &GetRows();

  void SetRows(const std::unordered_map<std::string, Row> &rows);

  friend std::istream &operator>>(std::istream &in, Table &table);
};