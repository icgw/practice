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
#include <queue>
using std::priority_queue;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
      int n = grid.size();
      int m = grid[0].size();
      priority_queue<int> pq;
      int k = (n * m + 1) / 2;
      vector<int> v;
      for (auto& g : grid) {
        v.insert(v.end(), g.begin(), g.end());
        for (int i : g) {
          pq.push(i);
          if (pq.size() > k) {
            pq.pop();
          }
        }
      }
      int mid = pq.top();
      int res = 0;
      for (int i : v) {
        int diff = abs(i - mid);
        if (diff % x != 0) {
          return -1;
        }
        res += (diff / x);
      }
      return res;
    }
};

#endif /* !_SOLUTION_H_ */

