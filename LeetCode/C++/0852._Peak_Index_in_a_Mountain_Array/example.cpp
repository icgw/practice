/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<int> mountain { 0, 2, 1, 0 };
  std::cout << sln.peakIndexInMountainArray(mountain) << std::endl;
}
