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
  vector<vector<int>> points { { 2, 1 }, { 2, 2 }, { 3, 3 } };
  vector<int> location { 1, 1 };
  std::cout << sln.visiblePoints(points, 90, location) << std::endl;
}

