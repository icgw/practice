/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<int> nums { 10, 100, 101, 101 };
  int target = 101;
  std::cout << sln.isMajorityElement(nums, target) << std::endl;
}
