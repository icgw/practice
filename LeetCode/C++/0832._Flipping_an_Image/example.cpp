/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<vector<int>> nums = { {1, 1, 0}, {1, 0, 1}, {0, 0, 0} };
  vector<vector<int>> ans = sln.flipAndInvertImage(nums);
  for (auto v : ans) {
    for (auto i : v) std::cout << i << " ";
    std::cout << "\n";
  }
}
