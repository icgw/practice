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
  vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << sln.maxArea(height) << "\n";
}

