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
  vector<int> scores { 1, 2, 3, 5 };
  vector<int> ages { 8, 9, 10, 1 };

  std::cout << sln.bestTeamScore(scores, ages) << "\n";
}
