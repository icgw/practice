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
  vector<vector<int>> mat{{1, 1, 3, 2, 4, 3, 2},
                          {1, 1, 3, 2, 4, 3, 2},
                          {1, 1, 3, 2, 4, 3, 2}};
  int threshold = 4;
  std::cout << sln.maxSideLength(mat, threshold) << "\n";
}

