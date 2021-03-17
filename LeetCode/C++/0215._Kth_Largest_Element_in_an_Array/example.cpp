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
  vector<int> nums{3, 2, 1, 5, 6, 4};
  int k = 2;
  std::cout << sln.findKthLargest(nums, k) << "\n";
}

