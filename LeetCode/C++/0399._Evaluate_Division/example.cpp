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

  vector<vector<string>> equations = { { "a", "b" }, { "b", "c" } };
  vector<double> values = { 2.0, 3.0 };
  vector<vector<string>> queries = { { "a", "c" }, { "b", "a" }, { "a", "e" }, { "a", "a" }, { "x", "x" } };

  vector<double> ans = sln.calcEquation(equations, values, queries);
  for (double a : ans) std::cout << a << std::endl;
}
