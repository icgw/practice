/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <algorithm>
using std::min;

class Solution {
public:
  int shortestSubarray(vector<int>& A, int K) {
    deque<int> dq;
    int n = A.size();
    int res = n + 1;
    vector<int> sumOfA(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      sumOfA[i] = sumOfA[i - 1] + A[i - 1];
      if (sumOfA[i] >= K) {
        res = min(res, i);
      }
      while (dq.size() > 0 && sumOfA[i] - sumOfA[dq.front()] >= K) {
        res = min(res, i - dq.front());
        dq.pop_front();
      }
      while (dq.size() > 0 && sumOfA[i] <= sumOfA[dq.back()]) {
        dq.pop_back();
      }
    }
    return res > n ? -1 : res;
  }
};

#endif /* !_SOLUTION_H_ */

