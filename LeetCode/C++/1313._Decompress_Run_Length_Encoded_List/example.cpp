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
  vector<int> nums { 1, 2, 3, 4 };
  vector<int> ans = sln.decompressRLElist(nums);
  for (int i : ans) std::cout << i << std::endl;
}
