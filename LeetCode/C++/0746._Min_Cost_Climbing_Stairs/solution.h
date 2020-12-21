/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <algorithm>
using std::min;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n <= 2) return 0;
    int prev, curr, next;
    prev = curr = 0;
    for (int i = 2; i <= n; ++i) {
      next = min(curr + cost[i - 1], prev + cost[i - 2]);
      prev = curr;
      curr = next;
    }
    return next;
  }
};

#endif /* !_SOLUTION_H_ */

