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
  vector<int> nums { 5, 7, 3, 9, 4, 9, 8, 3, 1 };
  std::cout << sln.largestUniqueNumber( nums ) << std::endl;
}
