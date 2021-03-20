/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <cstdlib>
using std::rand;
#include "../data_structures.hpp"

class Solution {
private:
  ListNode* head_;
public:
  Solution(ListNode* head) : head_(head) {}

  int getRandom() {
    int val = head_->val;
    ListNode* cur = head_->next;
    int i = 2;
    while (cur) {
      if (rand() % i == 0) val = cur->val;
      ++i;
      cur = cur->next;
    }
    return val;
  }
};

#endif /* !_SOLUTION_H_ */

