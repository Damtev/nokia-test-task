//
// Created by damtev on 29.07.2020.
//

#pragma once

#include <exception>
#include <string>
#include <filesystem>

class ParsingException : public std::exception {
 public:
  explicit ParsingException(const std::filesystem::path &path) : path_(path) {}

  [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return "It should never be printed";
  }

 protected:
  const std::filesystem::path &path_;
};