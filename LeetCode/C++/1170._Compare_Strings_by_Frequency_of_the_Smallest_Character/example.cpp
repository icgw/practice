/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example() {
  Solution sln;
  vector<string> queries = { "bbb", "cc" }, words = { "a", "aa", "aaa", "aaaa" };
  vector<int> answers = sln.numSmallerByFrequency(queries, words);

  for (int a : answers) {
    std::cout << a << std::endl;
  }
}
