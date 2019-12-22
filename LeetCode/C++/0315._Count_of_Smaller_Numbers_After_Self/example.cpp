/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;

  vector<int> nums { 5, 2, 6, 1 };
  vector<int> ans = sln.countSmaller(nums);

  for (int a : ans) {
    std::cout << a << std::endl;
  }
}
