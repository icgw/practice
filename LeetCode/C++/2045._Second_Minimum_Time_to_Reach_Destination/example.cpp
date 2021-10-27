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
  int n = 5;
  vector<vector<int>> edges {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
  Solution sln;
  std::cout << sln.secondMinimum(n, edges, 3, 5) << "\n";
}

