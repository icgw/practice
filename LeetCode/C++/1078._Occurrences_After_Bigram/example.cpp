/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "solution.hpp"

void run_example()
{
  Solution sln;
  string text = "alice is a good girl she is a good student",
         first = "a",
         second = "good";
  for (auto &s : sln.findOcurrences(text, first, second)) {
    std::cout << s << ", ";
  }
  std::cout << std::endl;
}
