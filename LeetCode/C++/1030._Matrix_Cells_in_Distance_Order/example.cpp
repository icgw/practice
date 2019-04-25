/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "solution.hpp"

void run_example() {
  Solution sln;
  int R = 2, C = 3, r0 = 1, c0 = 2;
  vector<vector<int>> ans = sln.allCellsDistOrder(R, C, r0, c0);
  for (auto &v : ans) {
    std::cout << "[" << v[0] << ", " << v[1] << "]" << std::endl;
  }
}
