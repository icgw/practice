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

  string source = "xyz", target = "xzyxz";
  std::cout << sln.shortestWay(source, target) << std::endl;
}
