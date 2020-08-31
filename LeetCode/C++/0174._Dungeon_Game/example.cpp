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

  vector<vector<int>> dungeon {
    { -2, -3, 3 },
    { -5, -10, 1 },
    { 10, 30, -5}
  };

  std::cout << sln.calculateMinimumHP( dungeon ) << std::endl;
}

