/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;

class Solution {
public:
  int maxNumberOfApples(vector<int>& arr) {
    constexpr int MAXIMUM = 5000;
    priority_queue<int> pq;
    int sum = 0, cnt = 0;
    for (int i : arr) {
      if (sum <= MAXIMUM - i) {
        pq.push(i);
        ++cnt;
        sum += i;
      }
      else if (!pq.empty() && i < pq.top()) {
        sum -= (pq.top() - i);
        pq.pop();
        pq.push(i);
      }
    }
    return cnt;
  }
};

#endif // ifndef _SOLUTION_HPP_
