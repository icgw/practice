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
  vector<vector<int>> v { { 1, 2 }, { 3 }, { 4 } };
  Vector2D v2d (v);

  std::cout << v2d.next()    << std::endl;
  std::cout << v2d.next()    << std::endl;
  std::cout << v2d.next()    << std::endl;
  std::cout << v2d.hasNext() << std::endl;
  std::cout << v2d.hasNext() << std::endl;
  std::cout << v2d.next()    << std::endl;
  std::cout << v2d.hasNext() << std::endl;
}
