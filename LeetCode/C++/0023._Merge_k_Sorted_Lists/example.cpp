/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  ListNode* list1 = stringToListNode("[1, 4, 5]");
  ListNode* list2 = stringToListNode("[1, 3, 4]");
  ListNode* list3 = stringToListNode("[2, 6]");
  vector<ListNode*> lists{};
  lists.push_back(list1);
  lists.push_back(list2);
  lists.push_back(list3);
  ListNode* res = sln.mergeKLists(lists);
  ListNode* ptr = res;
  while (ptr) {
    std::cout << ptr->val << "\n";
    ptr = ptr->next;
  }
}

