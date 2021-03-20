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
  vector<int> nums{1, 2, 3, 3, 3};
  Solution sln(nums);
  std::cout << sln.pick(3) << "\n";
  std::cout << sln.pick(1) << "\n";
}

