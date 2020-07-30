#### Description

It is a test task for C++ trainee in Nokia. The whole descirption is described in [Anketa4Students_C++.docx](Anketa4Students_C++.docx).

#### Build

To build the project, run `cmake <project_dir>` and `make` in directory where you want to get executable file.

#### Run

To process CSV file, pass one or more paths to CSV files to executable file `csv_values_processor`.

#### Input format

CSV file should satisfy the following format:
* The first line should fully matches the following regular expression: `^,[a-zA-Z]+(,[a-zA-Z]+)*$` (empty value, then strings, composed of only latin letters)
* All column indices (values at first line) should be unique
* Then follows unlimited number of lines, in which the first value is non-negative integer, that could be represented as `size_t`, and other values fully match the following regular expression: `^(\d+|=[^,\s]+\d+[+-\/*][^,\s]+\d+)$` (positive integer or one of the following operators:[+-/*] with two other values, preceded by sign **=**; whitespaces are not allowed)
* All row indices (first values at lines) should be unique