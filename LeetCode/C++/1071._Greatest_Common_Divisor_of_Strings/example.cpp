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
  string str1 = "ABABAB", str2 = "ABAB";
  std::cout << sln.gcdOfStrings(str1, str2) << "\n";
}

