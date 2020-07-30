//
// Created by damtev on 28.07.2020.
//

#pragma once
#include "../cell.hpp"

namespace cell::unary_operation {

 using namespace cell::unary_operation;

 class Const final : public Cell {
  private:
   long long value_;

  public:
   Const() = delete;

   Const(std::string_view column_id, size_t row_id, long long int value);

   ~Const() override = default;

   [[nodiscard]] long long int GetValue() const;

   void SetValue(long long int value);

   long long int Evaluate() override;
 };
}