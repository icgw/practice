/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  string word1 = "leetcode", word2 = "etco";
  std::cout << sln.minDistance(word1, word2) << "\n";
}

