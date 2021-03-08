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
  vector<int> nums { 5, 4, 0, 3, 1, 6, 2 };
  std::cout << sln.arrayNesting(nums) << "\n";
}

