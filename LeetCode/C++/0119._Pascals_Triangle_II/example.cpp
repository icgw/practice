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
  for (int i : sln.getRow(3)) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}
