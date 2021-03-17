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
  vector<int> nums{1, 2, 3};
  vector<vector<int>> res = sln.permute(nums);
  for (auto& r : res) {
    for (int i : r) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}

