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
  vector<int> nums{1, 2, 3, 4};
  vector<int> ans = sln.productExceptSelf(nums);
  for (auto a : ans) std::cout << a << "\n";
}

