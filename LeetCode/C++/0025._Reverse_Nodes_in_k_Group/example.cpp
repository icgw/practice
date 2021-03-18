/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  ListNode* lst = stringToListNode("[1, 2, 3, 4, 5]");
  Solution sln;
  ListNode* res = sln.reverseKGroup(lst, 2);
  ListNode* ptr = res;
  while (ptr) {
    std::cout << ptr->val << "\n";
    ptr = ptr->next;
  }
}

