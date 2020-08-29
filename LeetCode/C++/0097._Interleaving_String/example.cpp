/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;

  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

  std::cout << sln.isInterleave(s1, s2, s3) << std::endl;
}
