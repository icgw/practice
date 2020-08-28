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

  string S = "babgbag", T = "bag";

  std::cout << sln.numDistinct(S, T) << std::endl;
}

