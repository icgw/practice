/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>

#include "solution.h"

void run_example()
{
  Solution sln;
  vector<vector<int>> points {
    { 1, 1 }, { 3, 2 }, { 5, 3 }, { 4, 1 }, { 2, 3 }, { 1, 4 }
  };

  std::cout << sln.maxPoints(points) << std::endl;
}
