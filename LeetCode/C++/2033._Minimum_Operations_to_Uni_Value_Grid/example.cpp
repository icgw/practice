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
  vector<vector<int>> grid = {{2, 4}, {6, 8}};
  std::cout << sln.minOperations(grid, 2) << "\n";
}

