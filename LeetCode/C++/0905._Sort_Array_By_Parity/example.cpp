/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<int> input { 3, 1, 2, 4 };
  vector<int> output = sln.sortArrayByParity(input);

  for (auto i : output) {
    std::cout << i << "\n";
  }

}
