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
  string expression = "|(&(t,f,t),!(t))";
  std::cout << sln.parseBoolExpr(expression) << std::endl;
}

