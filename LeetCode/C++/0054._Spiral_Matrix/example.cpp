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
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> res = sln.spiralOrder(matrix);
  for (int i : res) std::cout << i << "\n";
}
