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
  vector<vector<int>> costs {
    { 10, 20 }, { 30, 200 }, { 400, 50 }, { 30, 20 }
  };
  int ans = sln.twoCitySchedCost(costs);
  std::cout << ans << std::endl;
}
