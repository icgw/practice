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
  string s = "barfoothefoobarman";
  vector<string> words{"foo", "bar"};
  vector<int> res = sln.findSubstring(s, words);
  for (int i : res) std::cout << i << "\n";
}

