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
#include <utility>
using std::pair;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<int> all_x;
    for (auto& b : buildings) {
      all_x.emplace_back(b[0]);
      all_x.emplace_back(b[1]);
    }
    sort(all_x.begin(), all_x.end());
    int idx = 0;
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> res;
    int n = buildings.size();
    for (int x : all_x) {
      while (idx < n && buildings[idx][0] <= x) {
        pq.push({buildings[idx][2], buildings[idx][1]});
        ++idx;
      }
      while (!pq.empty() && pq.top().second <= x) {
        pq.pop();
      }
      int max_y = pq.empty() ? 0 : pq.top().first;
      if (res.empty() || max_y != res.back()[1]) {
        res.push_back({x, max_y});
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

