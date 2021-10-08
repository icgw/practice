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
  string s = "abpcplea";
  vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
  std::cout << sln.findLongestWord(s, dictionary) << "\n";
}

