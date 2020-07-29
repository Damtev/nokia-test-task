//
// Created by damtev on 28.07.2020.
//

#pragma once

#include "../cell.hpp"

namespace cell::binary_operation {

 using namespace cell::binary_operation;

 class BinaryOperation : public Cell {
  public:
   BinaryOperation(std::string_view column_id, size_t row_id);

   BinaryOperation(std::string_view column_id, size_t row_id, Cell *left, Cell *right);

   ~BinaryOperation();

   [[nodiscard]] Cell *GetFirstOperand() const;

   void SetFirstOperand(Cell *first_operand);

   [[nodiscard]] Cell *GetSecondOperand() const;

   void SetSecondOperand(Cell *second_operand);

   long long int Evaluate() override final;

  protected:
   Cell *first_operand_ = nullptr;
   Cell *second_operand_ = nullptr;

   virtual long long Operation(long long first_value, long long second_value) = 0;
 };
}