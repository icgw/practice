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
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  std::cout << sln.search(nums, target) << "\n";
}

