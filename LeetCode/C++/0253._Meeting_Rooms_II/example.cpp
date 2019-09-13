/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<vector<int>> intervals { { 0, 30 }, { 5, 10 }, { 15, 20 } };
  int minNumber = sln.minMeetingRooms(intervals);
  std::cout << minNumber << std::endl;
}
