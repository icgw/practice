/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  vector<int> arr { 40, 10, 20, 30 };
  vector<int> ans = sln.arrayRankTransform(arr);
  for (int a : ans) std::cout << a << std::endl;
}
