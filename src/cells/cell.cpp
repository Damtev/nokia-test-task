//
// Created by damtev on 28.07.2020.
//

#include "cell.hpp"

using namespace cell;

Cell::Cell(std::string_view column_id, const size_t row_id)
    : state_(EvaluationState::kNotEvaluated), column_id_(column_id), row_id_(row_id) {}

EvaluationState Cell::GetState() const {
  return state_;
}

void Cell::SetState(cell::EvaluationState state) {
  state_ = state;
}

const std::string &Cell::GetColumnId() const {
  return column_id_;
}

void Cell::SetColumnId(const std::string &column_id) {
  column_id_ = column_id;
}

size_t Cell::GetRowId() const {
  return row_id_;
}

void Cell::SetRowId(size_t row_id) {
  row_id_ = row_id;
}

std::string Cell::GetPosition() const {
  return column_id_ + std::to_string(row_id_);
}