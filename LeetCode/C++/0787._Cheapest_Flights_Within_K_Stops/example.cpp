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
  int n = 3;
  vector<vector<int>> flights {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0, dst = 2, k = 1;
  std::cout << sln.findCheapestPrice(n, flights, src, dst, k) << "\n";
}
