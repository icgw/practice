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
  Logger logger;

  std::cout << logger.shouldPrintMessage(1,  "foo") << std::endl;
  std::cout << logger.shouldPrintMessage(2,  "bar") << std::endl;
  std::cout << logger.shouldPrintMessage(3,  "foo") << std::endl;
  std::cout << logger.shouldPrintMessage(8,  "bar") << std::endl;
  std::cout << logger.shouldPrintMessage(10, "foo") << std::endl;
  std::cout << logger.shouldPrintMessage(11, "foo") << std::endl;
}
