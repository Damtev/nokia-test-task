//
// Created by damtev on 28.07.2020.
//

#include "binary_operation.hpp"
#include "../../exceptions/evaluation/recursion_exception.hpp"

using namespace cell;
using namespace cell::binary_operation;

BinaryOperation::BinaryOperation(std::string_view column_id, size_t row_id) : Cell(column_id, row_id) {}

BinaryOperation::BinaryOperation(std::string_view column_id, const size_t row_id, Cell *left, Cell *right) : BinaryOperation(column_id, row_id) {
  first_operand_ = left;
  second_operand_ = right;
}

BinaryOperation::~BinaryOperation() {
  // todo: it fails if uncomment
//  delete first_operand_;
//  delete second_operand_;
}

Cell *BinaryOperation::GetFirstOperand() const {
  return first_operand_;
}

void BinaryOperation::SetFirstOperand(Cell *first_operand) {
  first_operand_ = first_operand;
}

Cell *BinaryOperation::GetSecondOperand() const {
  return second_operand_;
}

void BinaryOperation::SetSecondOperand(Cell *second_operand) {
  second_operand_ = second_operand;
}

long long int BinaryOperation::Evaluate() {
  if (evaluated_value.has_value()) {
    return evaluated_value.value();
  }

  if (state_ == EvaluationState::kEvaluating) {
    throw RecursionException(this);
  }

  state_ = EvaluationState::kEvaluating;
  evaluated_value = Operation(first_operand_->Evaluate(), second_operand_->Evaluate());
  return evaluated_value.value();
}