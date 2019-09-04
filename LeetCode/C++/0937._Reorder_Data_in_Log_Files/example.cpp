/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example() {
  vector<string> logs = {
    "dig1 8 1 5 1",
    "let1 art can",
    "dig2 3 6",
    "let2 own kit dig",
    "let3 art zero"
  };

  Solution sln;
  sln.reorderLogFiles(logs);

  for (string s : logs) std::cout << s << std::endl;
}
