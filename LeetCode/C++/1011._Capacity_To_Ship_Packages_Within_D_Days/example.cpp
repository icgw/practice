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
  vector<int> weights { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::cout << sln.shipWithinDays(weights, 5) << "\n";
}

