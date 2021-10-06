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
  vector<int> prices {7, 1, 5, 3, 6, 4};
  std::cout << sln.maxProfit(prices) << "\n";
}

