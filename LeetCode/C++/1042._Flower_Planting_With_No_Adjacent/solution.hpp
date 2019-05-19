/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> graph ( N );
    for (auto &p : paths) {
      graph[p[0] - 1].push_back(p[1] - 1);
      graph[p[1] - 1].push_back(p[0] - 1);
    }

    vector<int> res (N, 0);
    for (int i = 0; i < N; ++i) {
      bool used[5] = {};
      for (auto n : graph[i]) {
        used[res[n]] = true;
      }
      for (int c = 1; c < 5; ++c) {
        if (!used[c]) {
          res[i] = c;
          break;
        }
      }
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
