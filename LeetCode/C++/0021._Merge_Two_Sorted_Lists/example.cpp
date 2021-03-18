/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  Solution sln;
  ListNode* l1 = stringToListNode("[1, 2, 4]");
  ListNode* l2 = stringToListNode("[1, 3, 4]");
  ListNode* l12 = sln.mergeTwoLists(l1, l2);
  ListNode* p = l12;
  while (p) {
    std::cout << p->val << "\n";
    p = p->next;
  }
}

