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
  vector<int> nums1 { 1, 2 }, nums2 { 3, 4 };
  std::cout << sln.findMedianSortedArrays( nums1, nums2 ) << std::endl;
}
