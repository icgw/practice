/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  BSTIterator bSTIterator(stringToTreeNode("[7, 3, 15, null, null, 9, 20]"));
  std::cout << bSTIterator.next() << "\n";
  std::cout << bSTIterator.next() << "\n";
  bSTIterator.hasNext();
  std::cout << bSTIterator.next() << "\n";
  bSTIterator.hasNext();
  std::cout << bSTIterator.next() << "\n";
  bSTIterator.hasNext();
  std::cout << bSTIterator.next() << "\n";
  bSTIterator.hasNext();
}

