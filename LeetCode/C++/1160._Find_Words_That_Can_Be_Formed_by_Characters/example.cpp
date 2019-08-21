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
  vector<string> words = { "cat", "bt", "hat", "tree" };
  int sum = sln.countCharacters(words, "atach");
  std::cout << sum << std::endl;
}
