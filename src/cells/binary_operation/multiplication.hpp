//
// Created by damtev on 28.07.2020.
//

#pragma once

#include "binary_operation.hpp"

namespace cell::binary_operation {

 using namespace cell::binary_operation;

 class Multiplication final : public BinaryOperation {
  public:
   Multiplication(std::string_view column_id, size_t row_id) : BinaryOperation(column_id, row_id) {}

  protected:
   long long int Operation(long long int first_value, long long int second_value) override;
 };
}