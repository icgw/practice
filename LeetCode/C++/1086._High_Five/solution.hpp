/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

#include <map>
using std::map;

class Solution {
public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    map<int, priority_queue<int>> m;
    for (auto &i : items) {
      m[i[0]].push(i[1]);
    }

    vector<vector<int>> res;
    for (auto e : m) {
      int cnt = 0, sum = 0;
      priority_queue<int> pq = e.second;
      for (int i = 0; !pq.empty() && i < 5; ++i) {
        sum += pq.top();
        pq.pop();
        ++cnt;
      }
      if (cnt == 0) continue;
      res.push_back( { e.first, sum / cnt } );
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
