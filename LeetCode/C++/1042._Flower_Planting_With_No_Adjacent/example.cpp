/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  int N = 3;
  vector<vector<int>> paths { { 1, 2 }, { 2, 3 }, { 3, 1 } };
  vector<int> ans = sln.gardenNoAdj(N, paths);
  for (auto i : ans) {
    std::cout << i << "\n";
  }
}
