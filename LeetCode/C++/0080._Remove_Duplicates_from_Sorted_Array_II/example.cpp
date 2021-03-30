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
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int n = sln.removeDuplicates(nums);
  for (int i = 0; i < n; ++i) {
    std::cout << nums[i] << "\n";
  }
}

