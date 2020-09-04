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

  vector<int> arr { 1, 2, 4, 4, 4, 4 };
  int m = 1, k = 3;

  std::cout << sln.containsPattern( arr, m, k ) << std::endl;
}

