/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include "../data_structures.hpp"

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
      head = l1;
      head->next = mergeTwoLists(l1->next, l2);
    } else {
      head = l2;
      head->next = mergeTwoLists(l1, l2->next);
    }
    return head;
  }
};

#endif /* !_SOLUTION_H_ */

