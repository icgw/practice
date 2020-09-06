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

  vector<vector<int>> matrix { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

  std::cout << sln.diagonalSum( matrix ) << std::endl;
}

