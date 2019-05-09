/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  vector<string> words = { "gin", "zen", "gig", "msg" };
  int ans = sln.uniqueMorseRepresentations(words);
  std::cout << ans << "\n";
}
