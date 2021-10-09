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
  vector<int> numbers {2, 7, 11, 15};
  for (auto i : sln.twoSum(numbers, 9)) {
    std::cout << i << "\n";
  }
}

