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
  ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* nxt = nullptr;
    while (cur) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
};

#endif /* !_SOLUTION_H_ */

