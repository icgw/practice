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
  int target = 11;
  vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << sln.minSubArrayLen(target, nums) << "\n";
}

