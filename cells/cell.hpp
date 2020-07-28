//
// Created by damtev on 28.07.2020.
//

#pragma once

#include <string>
#include <optional>
#include "evaluation_state.hpp"

namespace cell {

 using namespace cell;

 class Cell {
  public:
   Cell(std::string_view column_id, size_t row_id);
   [[nodiscard]] EvaluationState GetState() const;

   void SetState(EvaluationState state);

   virtual long long Evaluate() = 0;

   [[nodiscard]] const std::string &GetColumnId() const;

   void SetColumnId(const std::string &column_id);

   [[nodiscard]] size_t GetRowId() const;

   void SetRowId(size_t row_id);

   [[nodiscard]] std::string GetPosition() const;

  protected:
   EvaluationState state_;
   std::string column_id_;
   size_t row_id_;
   std::optional<long long> evaluated_value = {};
 };
}