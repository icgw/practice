/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include "solution.h"
#include <iostream>

void run_example()
{
  Solution sln;
  vector<int> v { 0, 4, 3, 0, 4 };
  std::cout << sln.specialArray( v ) << std::endl;
}

