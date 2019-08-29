/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include "solution.hpp"

void run_example() {
  Solution sln;
  string s = "2004-03-01";
  int days = sln.dayOfYear(s);
  std::cout << days << std::endl;
}
