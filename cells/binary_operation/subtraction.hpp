//
// Created by damtev on 28.07.2020.
//

#pragma once

#include "binary_operation.hpp"

namespace cell::binary_operation {

 using namespace cell::binary_operation;

 class Subtraction final : public BinaryOperation {
  public:
  protected:
   long long int Operation(long long int first_value, long long int second_value) override;
 };
}

