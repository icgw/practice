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
  vector<string> equations{"a==b", "b!=c", "c==a"};
  std::cout << (sln.equationsPossible(equations) == false ? "false" : "true") << "\n";
}

