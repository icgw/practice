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
#include <algorithm>
using std::min;

class Solution {
  int step_to_time(int step, int time, int change) {
    int r = 0;
    for (int i = 0; i < step; ++i) {
      if ((r / change) % 2 == 1) {
        r = ((r / change) + 1) * change;
      }
      r += time;
    }
    return r;
  }
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> adj(n + 1);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> q{1};
    int step = -1;
    vector<int> min_step(n + 1, 1e4);
    while (!q.empty() && ++step <= min_step[n] + 1) {
      vector<int> next_q;
      for (int i : q) {
        if (step == min_step[i] || step > min_step[i] + 1) {
          continue;
        }
        min_step[i] = min(step, min_step[i]);
        if (i == n && step > min_step[n]) {
          return step_to_time(step, time, change);
        }
        for (int nei : adj[i]) {
          next_q.push_back(nei);
        }
      }
      q.swap(next_q);
    }
    return step_to_time(min_step[n] + 2, time, change);
  }
};

#endif /* !_SOLUTION_H_ */

