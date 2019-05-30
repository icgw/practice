/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (auto s : stones) pq.push(s);
    while (pq.size() > 1) {
      int first_heavy  = pq.top(); pq.pop();
      int second_heavy = pq.top(); pq.pop();
      if (first_heavy != second_heavy) {
        pq.push(first_heavy - second_heavy);
      }
    }
    return pq.empty() ? 0 : pq.top();
  }
};

#endif // ifndef _SOLUTION_HPP_
