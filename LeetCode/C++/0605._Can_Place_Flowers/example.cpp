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
  vector<int> flowerbed {1, 0, 0, 0, 1};
  std::cout << sln.canPlaceFlowers(flowerbed, 2) << "\n";
}

