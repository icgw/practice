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
  vector<vector<int>> buildings{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  auto res = sln.getSkyline(buildings);
  for (auto& r : res) {
    std::cout << r[0] << " " << r[1] << "\n";
  }
}

