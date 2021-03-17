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
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << sln.maxSubArray(nums) << "\n";
}

