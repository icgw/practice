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
  vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
  int k = 2;
  for (auto& topKWord : sln.topKFrequent(words, k)) {
    std::cout << topKWord << "\n";
  }
}

