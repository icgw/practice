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
  string S = "{a,b}c{d,e}f";
  vector<string> expandS = sln.expand(S);
  for (string es : expandS) {
    std::cout << es << std::endl;
  }
}
