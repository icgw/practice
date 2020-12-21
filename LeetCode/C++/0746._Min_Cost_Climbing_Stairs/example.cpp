/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  vector<int> cost { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
  std::cout << sln.minCostClimbingStairs(cost) << "\n";
}

