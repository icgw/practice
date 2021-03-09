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
  vector<vector<int>> firstList{{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector<vector<int>> secondList{{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  vector<vector<int>> intersectionList = sln.intervalIntersection(firstList, secondList);
  for (auto& i : intersectionList) {
    std::cout << "[" << i[0] << ", " << i[1] << "]\n";
  }
}

