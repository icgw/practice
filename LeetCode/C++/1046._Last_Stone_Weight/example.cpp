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
  vector<int> stones { 2, 7, 4, 1, 8, 1 };
  std::cout << sln.lastStoneWeight(stones) << "\n";
}
