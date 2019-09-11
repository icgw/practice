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
  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(2);

  std::cout << mf.findMedian() << std::endl; // 1.5

  mf.addNum(3);

  std::cout << mf.findMedian() << std::endl; // 2.0
}
