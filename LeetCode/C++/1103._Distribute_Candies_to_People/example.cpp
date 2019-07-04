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
  vector<int> ans = sln.distributeCandies(7, 4);
  for (int i : ans) std::cout << i << " ";
  std::cout << "\n";
}
