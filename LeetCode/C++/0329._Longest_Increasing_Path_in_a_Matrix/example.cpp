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

  vector<vector<int>> matrix {
    { 3, 4, 5 },
    { 3, 2, 6 },
    { 2, 2, 1 }
  };

  std::cout << sln.longestIncreasingPath(matrix) << std::endl;
}
