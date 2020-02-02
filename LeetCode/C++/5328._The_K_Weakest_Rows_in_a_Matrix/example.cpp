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
  vector<vector<int>> mat {
    { 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 1 }
  };
  int k = 3;
  vector<int> ans = sln.kWeakestRows( mat, k );

  for (int i : ans) std::cout << i << std::endl;
}
