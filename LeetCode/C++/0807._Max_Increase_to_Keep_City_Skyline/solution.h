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
using std::max;
using std::min;

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res += (min(row[i], col[j]) - grid[i][j]);
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

