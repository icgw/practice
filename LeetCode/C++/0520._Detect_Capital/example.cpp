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
  string word1 = "USA";
  string word2 = "FlaG";
  std::cout << sln.detectCapitalUse(word1) << "\n";
  std::cout << sln.detectCapitalUse(word2) << "\n";
}

