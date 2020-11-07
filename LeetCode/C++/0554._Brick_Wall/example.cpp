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
  vector<vector<int>> bricks {
    {1, 2, 2, 1},
    {3, 1, 2},
    {1, 3, 2},
    {2, 4},
    {3, 1, 2},
    {1, 3, 1, 1}
  };

  std::cout << sln.leastBricks(bricks) << "\n";
}

