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
  vector<int> arr { 5, 7, 11, 13 };
  std::cout << sln.missingNumber( arr ) << std::endl;
}
