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
  vector<int> arr { 900, 950, 800, 1000, 700, 800 };
  std::cout << sln.maxNumberOfApples(arr) << std::endl;
}
