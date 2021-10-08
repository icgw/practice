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
  vector<vector<int>> grid {
    {3, 0, 8, 4},
    {2, 4, 5, 7},
    {9, 2, 6, 3},
    {0, 3, 1, 0}
  };
  std::cout << sln.maxIncreaseKeepingSkyline(grid) << "\n";
}

