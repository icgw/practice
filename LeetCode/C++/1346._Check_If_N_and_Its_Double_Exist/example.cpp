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

  vector<int> arr { 10, 2, 5, 3 };

  std::cout << sln.checkIfExist(arr) << std::endl;
}
