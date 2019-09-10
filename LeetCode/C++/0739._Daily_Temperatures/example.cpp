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
  vector<int> T { 73, 74, 75, 71, 69, 72, 76, 73 };
  vector<int> ans = sln.dailyTemperatures(T);
  for (int a : ans) std::cout << a << "\n";
}
