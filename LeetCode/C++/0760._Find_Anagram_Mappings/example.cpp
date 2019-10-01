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
  vector<int> A { 12, 28, 46, 32, 50 }, B { 50, 12, 32, 46, 28 };
  vector<int> P = sln.anagramMappings(A, B);

  for (int p : P) std::cout << p << std::endl;
}
