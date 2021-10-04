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
#include <array>
using std::array;

class Solution {
public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> res(n, 0);
    vector<vector<int>> graph(n);
    for (auto& p : paths) {
      int n1 = p[0] - 1;
      int n2 = p[1] - 1;
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
    }
    for (int i = 0; i < n; ++i) {
      array<bool, 5> colors = {false, false, false, false, false};
      for (auto nbr : graph[i]) {
        colors[res[nbr]] = true;
      }
      for (int c = 1; c <= 4; ++c) {
        if (!colors[c]) {
          res[i] = c;
          break;
        }
      }
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
