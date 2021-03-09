/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <vector>
using std::vector;
#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  vector<vector<int>> points{{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
  std::cout << sln.minAreaRect(points) << "\n";
}

