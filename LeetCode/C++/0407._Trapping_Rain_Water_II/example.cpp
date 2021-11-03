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
  vector<vector<int>> heightMap {
    {1, 4, 3, 1, 3, 2},
    {3, 2, 1, 3, 2, 4},
    {2, 3, 3, 2, 3, 1}
  };
  std::cout << sln.trapRainWater(heightMap) << "\n";
}

