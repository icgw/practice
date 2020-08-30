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

  vector<int> prices { 3, 3, 5, 0, 0, 3, 1, 4 };

  std::cout << sln.maxProfit(prices) << std::endl;
}

