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
  int a = 1, b = 2, c = 5;
  vector<int> ans = sln.numMovesStones(a, b, c);
  std::cout << "[" << ans[0] << ", " << ans[1] << "]\n";
}
