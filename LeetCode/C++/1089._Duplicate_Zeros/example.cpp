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
  vector<int> nums { 1, 0, 2, 3, 0, 4, 5, 0 };
  sln.duplicateZeros(nums);
  for (auto i : nums) std::cout << i << std::endl;
}
