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
  vector<int> nums1 { 1, 2, 3, 4, 5, 6 };
  vector<int> nums2 { 1, 1, 2, 2, 2, 2 };
  std::cout << sln.minOperations(nums1, nums2) << "\n";
}

