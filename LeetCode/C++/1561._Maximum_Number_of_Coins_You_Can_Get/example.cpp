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
  vector<int> piles1 { 2, 4, 1, 2, 7, 8 };
  vector<int> piles2 { 2, 4, 5 };
  vector<int> piles3 { 9, 8, 7, 6, 5, 1, 2, 3, 4 };

  std::cout << sln.maxCoins(piles1) << std::endl;
  std::cout << sln.maxCoins(piles2) << std::endl;
  std::cout << sln.maxCoins(piles3) << std::endl;
}

