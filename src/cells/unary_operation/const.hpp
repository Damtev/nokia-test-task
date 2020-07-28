//
// Created by damtev on 28.07.2020.
//

#pragma once
#include "../cell.hpp"

namespace cell::unary_operator {

 using namespace cell::unary_operator;

 class Const final : public Cell {
   long long value_;

  public:
   Const(std::string_view column_id, size_t row_id, long long int value);

   [[nodiscard]] long long int GetValue() const;

   void SetValue(long long int value);

   long long int Evaluate() override;
 };
}