//
// Created by damtev on 29.07.2020.
//

#pragma once

extern inline const char *const kLineSeparator() {
#ifdef _WIN32
  return "\r\n";
#elif __linux__
  return "\n";
#else
  return "\r";
#endif
}
//  extern const char *const kLineSeparator = "\r\n";

extern inline const char kCellsSeparator = ',';

extern inline const char *const kCsvExtension = ".csv";

extern inline const char *const kBinaryOperatorsRegex = "[+-\\/*]";

extern inline const char *const kColumnIdRegex = "^[a-zA-Z]+$";

extern inline const char *const kRowIdRegex = "[1-9]\\d*";

extern inline const char *const kHeaderRegex = "^,[a-zA-Z]+(,[a-zA-Z]+)*$";

extern inline const char *const kNumberRegex = "^\\d+$";

extern inline const char *const kBinaryOperationRegex = "^=[^,\\s]+\\d+[+-\\/*][^,\\s]+\\d+$";

extern inline const char *const kCellRegex = "^(\\d+|=[^,\\s]+\\d+[+-\\/*][^,\\s]+\\d+)$";
