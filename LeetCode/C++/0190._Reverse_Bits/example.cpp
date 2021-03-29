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
  uint32_t n = 0b00000010100101000001111010011100;
  std::cout << sln.reverseBits(n) << "\n";
}

