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
  vector<int> A { 34, 23, 1, 24, 75, 33, 54, 8 };
  int K = 60;
  std::cout << sln.twoSumLessThanK(A, K) << std::endl;
}
