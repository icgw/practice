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
#include <array>
using std::array;
#include <queue>
using std::priority_queue;
#include <algorithm>
using std::max;

class Solution {
  using i3 = array<int, 3>;
  const vector<array<int, 2>> DIRS {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      auto cmp = [](const i3& a, const i3& b) { return a[0] > b[0]; };
      priority_queue<i3, vector<i3>, decltype(cmp)> pq(cmp);
      int n = heightMap.size();
      int m = heightMap[0].size();
      vector<vector<bool>> visited(n, vector<bool>(m, false));
      for (int i = 0; i < n; ++i) {
        pq.push({heightMap[i][0], i, 0});
        pq.push({heightMap[i][m - 1], i, m - 1});
        visited[i][0] = visited[i][m - 1] = true;
      }
      for (int j = 0; j < m; ++j) {
        pq.push({heightMap[0][j], 0, j});
        pq.push({heightMap[n - 1][j], n - 1, j});
        visited[0][j] = visited[n - 1][j] = true;
      }
      int res = 0;
      while (!pq.empty()) {
        auto [h, i, j] = pq.top();
        pq.pop();
        for (auto& d : DIRS) {
          int ii = i + d[0], jj = j + d[1];
          if (ii < 0 || ii >= n || jj < 0 || jj >= m || visited[ii][jj]) {
            continue;
          }
          res += max(0, h - heightMap[ii][jj]);
          visited[ii][jj] = true;
          pq.push({max(h, heightMap[ii][jj]), ii, jj});
        }
      }
      return res;
    }
};

#endif /* !_SOLUTION_H_ */

