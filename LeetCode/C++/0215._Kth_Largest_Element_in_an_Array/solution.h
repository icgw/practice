/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <queue>
using std::priority_queue;
#include <vector>
using std::vector;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    auto cmp = [](const int& l, const int& r) {
      return l > r;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i : nums) {
      if (pq.size() < k || i > pq.top()) {
        pq.push(i);
      }
      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};

#endif /* !_SOLUTION_H_ */

