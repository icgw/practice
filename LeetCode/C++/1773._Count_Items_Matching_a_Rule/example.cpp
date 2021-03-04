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
  vector<vector<string>> items { { "phone", "blue", "pixel" }, { "computer", "silver", "phone" }, { "phone", "gold", "iphone" } };
  std::cout << sln.countMatches(items, "color", "silver") << "\n";
  std::cout << sln.countMatches(items, "type", "phone") << "\n";
}
