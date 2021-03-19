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
  vector<int> arr{60864, 25176, 27249, 21296, 20204};
  int target = 56803;
  Solution sln;
  std::cout << sln.findBestValue(arr, target) << "\n";
}

