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
  std::cout << sln.convert("PAYPALISHIRING", 3) << "\n";
  std::cout << sln.convert("PAYPALISHIRING", 4) << "\n";
  std::cout << sln.convert("A", 1) << "\n";
}

