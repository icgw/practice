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
  string text1 = "abcde", text2 = "ace";
  std::cout << sln.longestCommonSubsequence(text1, text2) << "\n";
}

