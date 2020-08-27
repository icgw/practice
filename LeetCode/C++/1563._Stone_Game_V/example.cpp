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
  vector<int> stoneValue { 6, 2, 3, 4, 5, 5 };

  std::cout << sln.stoneGameV(stoneValue) << std::endl;
}
