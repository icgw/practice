/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  string keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode";
  std::cout << sln.calculateTime(keyboard, word) << std::endl;
}
