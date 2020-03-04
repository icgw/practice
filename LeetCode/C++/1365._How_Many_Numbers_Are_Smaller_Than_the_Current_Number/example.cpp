/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>

#include "solution.h"

void run_example()
{
  Solution sln;

  vector<int> nums { 8, 1, 2, 2, 3 };
  vector<int> res = sln.smallerNumbersThanCurrent(nums);

  for (int r : res) std::cout << r << std::endl;
}
