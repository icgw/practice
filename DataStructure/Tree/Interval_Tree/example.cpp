/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "interval_tree.hpp"

int main()
{
  IntervalTree it;
  Interval ints[] = {
    { 15, 20 }, { 10, 30 }, { 17, 19 }, { 5, 20 }, { 12, 15 }, { 30, 40 }
  };
  for (auto i : ints) {
    it.insert(i);
  }

  Interval x = { 6, 7 };
  Interval *res = it.overlapSearch(x);
  if (res != nullptr) {
    std::cout << "\nOverlaps with [" << res->low << ", " << res->high << "]\n";
  }

  return 0;
}
