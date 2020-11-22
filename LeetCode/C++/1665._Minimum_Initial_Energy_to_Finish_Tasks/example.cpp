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
  vector<vector<int>> tasks {
    {1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}
  };
  std::cout << sln.minimumEffort(tasks) << "\n";
}

