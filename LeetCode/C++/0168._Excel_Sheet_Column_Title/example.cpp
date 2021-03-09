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
  std::cout << sln.convertToTile(1) << "\n";
  std::cout << sln.convertToTile(28) << "\n";
  std::cout << sln.convertToTile(701) << "\n";
  std::cout << sln.convertToTile(2147483647) << "\n";
}
