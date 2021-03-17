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
  vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> res = sln.merge(intervals);
  for (auto& i : res) std::cout << i[0] << ", " << i[1] << "\n";
}

