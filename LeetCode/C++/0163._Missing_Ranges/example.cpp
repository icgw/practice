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
  vector<int> nums { 0, 1, 3, 50, 75 };
  int lower = 0, upper = 99;
  vector<string> ans = sln.findMissingRanges(nums, lower, upper);
  for (string s : ans) std::cout << s << std::endl;
}
