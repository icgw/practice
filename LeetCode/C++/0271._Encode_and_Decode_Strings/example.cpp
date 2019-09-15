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
  Codec coder;
  vector<string> s = { "Hello", "World" };
  string encoded = coder.encode(s);
  vector<string> decoded = coder.decode(encoded);
  for (string d : decoded) {
    std::cout << d << std::endl;
  }
}
