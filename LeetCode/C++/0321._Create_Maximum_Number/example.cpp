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

  vector<int> nums1 { 6, 7 };
  vector<int> nums2 { 6, 0, 4 };
  int k = 5;

  for (int i : sln.maxNumber( nums1, nums2, k )) {
    std::cout << i << std::endl;
  }
}

