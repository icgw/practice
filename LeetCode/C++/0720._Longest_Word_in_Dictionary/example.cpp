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
  vector<string> words {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  std::cout << sln.longestWord(words) << "\n";
}
