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
  string s = "leetcodeisacommunityforcoders";
  Solution sln;
  std::cout << sln.removeVowels(s) << std::endl;
}
