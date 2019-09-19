/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<vector<int>> workers { { 0, 0 }, { 1, 1 }, { 2, 0 } };
  vector<vector<int>> bikes { { 1, 0 }, { 2, 2 }, { 2, 1 } };

  vector<int> ans = sln.assignBikes( workers, bikes );
  for (auto i : ans) std::cout << i << std::endl;
}
