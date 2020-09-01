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

  vector<int> stocks { 3, 2, 6, 5, 0, 3 };
  int k = 2;

  std::cout << sln.maxProfit( k, stocks ) << std::endl;
}

