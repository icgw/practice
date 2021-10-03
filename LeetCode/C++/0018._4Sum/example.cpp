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
  vector<int> nums {1, 0, -1, 0, -2, 2};
  int target = 0;
  Solution sln;
  for (auto& v : sln.fourSum(nums, target)) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}
