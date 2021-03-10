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
  vector<vector<int>> points{{8, 7}, {9, 9}, {7, 4}, {9, 7}};
  std::cout << sln.maxWidthOfVerticalArea(points) << "\n";
}

