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
  vector<int> A{4, 5, 0, -2, -3, 1};
  int K = 5;
  std::cout << sln.subarraysDivByK(A, K) << "\n";
}

