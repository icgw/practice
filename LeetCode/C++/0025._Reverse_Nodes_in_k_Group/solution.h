/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <memory>
using std::unique_ptr;
#include <tuple>
using std::tie;
#include <utility>
using std::make_pair;

#include "../data_structures.hpp"

class Solution {
public:
/* // 递归的解法.
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cursor = head;
    for (int i = 0; i < k; ++i) {
      if (cursor == nullptr) {
        return head;
      }
      cursor = cursor->next;
    }
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* nxt = nullptr;
    for (int i = 0; i < k; ++i) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    head->next = reverseKGroup(cur, k);
    return pre;
  }
*/
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto reverseList = [](ListNode* const h, ListNode* const t) -> decltype(auto) {
      ListNode* pre = h;
      ListNode* nxt = h->next;
      while (pre != nullptr && pre != t) {
        ListNode* tmp_nxt = nxt->next;
        nxt->next = pre;
        pre = nxt;
        nxt = tmp_nxt;
      }
      return make_pair(t, h);
    };
    unique_ptr<ListNode> dummy(new ListNode(0));
    dummy->next = head;
    ListNode* pre = dummy.get();
    while (head) {
      ListNode* tail = pre;
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (!tail) {
          return dummy->next;
        }
      }
      ListNode* tmp_head = tail->next;
      tie(head, tail) = reverseList(head, tail);

      pre->next = head;
      tail->next = tmp_head;

      head = tmp_head;
      pre = tail;
    }
    return dummy->next;
  }
};

#endif /* !_SOLUTION_H_ */

