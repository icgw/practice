/*
 * solution.h
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;
#include <limits>
using std::numeric_limits;
#include <algorithm>
using std::max;

class Solution {
private:
  const vector<vector<int>> DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int longestIncreasingPathHelper(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j, int pre) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] <= pre) {
      return 0;
    }
    if (cache[i][j] > 0) {
      return cache[i][j];
    }
    int cur = matrix[i][j];
    int res = 1;
    matrix[i][j] = numeric_limits<int>::min();
    for (auto& d : DIRS) {
      res = max(res, 1 + longestIncreasingPathHelper(matrix, cache, i + d[0], j + d[1], cur));
    }
    matrix[i][j] = cur;
    cache[i][j] = res;
    return res;
  }

public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 1;
    vector<vector<int>> cache(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        res = max(res, longestIncreasingPathHelper(matrix, cache, i, j, numeric_limits<int>::min()));
      }
    }
    return res;
  }
};

#endif /* !SOLUTION_H */
