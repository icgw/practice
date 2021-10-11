/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include <memory>

#include "solution.h"

void run_example()
{
  auto obj = std::make_unique<StockPrice>();
  obj->update(1, 10);
  obj->update(2, 5);
  std::cout << obj->current() << "\n";
  std::cout << obj->maximum() << "\n";
  obj->update(1, 3);
  std::cout << obj->maximum() << "\n";
  obj->update(4, 2);
  std::cout << obj->minimum() << "\n";
}
