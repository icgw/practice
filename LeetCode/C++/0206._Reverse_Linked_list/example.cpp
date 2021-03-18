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
  ListNode* head = stringToListNode("[1, 2, 3, 4, 5]");
  ListNode* res = sln.reverseList(head);
  ListNode* p = res;
  while (p) {
    std::cout << p->val << "\n";
    p = p->next;
  }
}

