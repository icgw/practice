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
  int N1 = 153, N2 = 123;
  std::cout << sln.isArmstrong(N1) << std::endl;
  std::cout << sln.isArmstrong(N2) << std::endl;
}
