/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  ListNode* head = stringToListNode("[1, 2, 3]");
  Solution sln(head);
  for (int i = 0; i < 30; ++i) {
    std::cout << sln.getRandom() << "\n";
  }
}

