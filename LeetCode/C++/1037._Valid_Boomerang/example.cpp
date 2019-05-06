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
  vector<vector<int>> points { { 1, 1 }, { 2, 3 }, { 3, 2 } };
  std::cout << sln.isBoomerang(points) << "\n";
}
