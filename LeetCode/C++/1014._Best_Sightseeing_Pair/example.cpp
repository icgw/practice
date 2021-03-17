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
  vector<int> values{8, 1, 5, 2, 6};
  std::cout << sln.maxScoreSightseeingPair(values) << "\n";
}

