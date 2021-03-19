/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <utility>
using std::pair;
#include <vector>
using std::vector;
#include <memory>
using std::unique_ptr;
#include <queue>
using std::priority_queue;
#include "../data_structures.hpp"

class Solution {
  using PIL = pair<int, ListNode*>;
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](const PIL& l, const PIL& r) {
      return l.first > r.first;
    };
    priority_queue<PIL, vector<PIL>, decltype(cmp)> pq(cmp);
    for (auto& lst : lists) {
      if (lst != nullptr) {
        pq.emplace(lst->val, lst);
      }
    }
    unique_ptr<ListNode> dummy(new ListNode(0));
    ListNode* ptr = dummy.get();
    while (!pq.empty()) {
      ListNode* head = pq.top().second;
      pq.pop();
      ptr->next = head;
      if (head->next) {
        pq.emplace(head->next->val, head->next);
      }
      ptr = ptr->next;
    }
    return dummy->next;
  }
};

#endif /* !_SOLUTION_H_ */

