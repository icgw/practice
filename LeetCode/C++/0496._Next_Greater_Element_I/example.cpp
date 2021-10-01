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
  vector<int> nums1 {4, 1, 2};
  vector<int> nums2 {1, 3, 4, 2};
  auto res = sln.nextGreaterElement(nums1, nums2);
  for (int i : res) {
    std::cout << i << "\n";
  }
}
