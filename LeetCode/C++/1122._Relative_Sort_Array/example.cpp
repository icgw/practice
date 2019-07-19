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
  vector<int> arr1 { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
  vector<int> arr2 { 2, 1, 4, 3, 9, 6 };

  vector<int> ans = sln.relativeSortArray(arr1, arr2);

  for (auto i : ans) std::cout << i << "\n";
}
