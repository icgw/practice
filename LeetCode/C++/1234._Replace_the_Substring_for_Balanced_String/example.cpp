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
  string s1 = "QWER";
  std::cout << sln.balancedString(s1) << "\n";
  string s2 = "QQWE";
  std::cout << sln.balancedString(s2) << "\n";
  string s3 = "QQQW";
  std::cout << sln.balancedString(s3) << "\n";
  string s4 = "QQQQ";
  std::cout << sln.balancedString(s4) << "\n";
}

