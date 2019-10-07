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
  vector<int> arr1 { 1, 2, 3, 4, 5 }, arr2 { 1, 2, 5, 7, 9 }, arr3 { 1, 3, 4, 5, 8 };
  vector<int> ans = sln.arraysIntersection(arr1, arr2, arr3);
  for (int i : ans) std::cout << i << std::endl;
}
