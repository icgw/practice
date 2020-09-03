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
  std::cout << sln.minOperations( 3 ) << std::endl;
  std::cout << sln.minOperations( 6 ) << std::endl;
}

