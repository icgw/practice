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

// Status: Time Limit Exceeded (135 / 138 test cases passed)
class Solution {
private:
  int longestIncreasingPathHelper(vector<vector<int>>& matrix,
                                  int i, int j,
                                  int m, int n,
                                  int v, int l // v: the current integer, l: the length
                                  ) {
    if (i < 0 || j < 0 || i >= m || j >= n) return l;

    int curr = matrix[i][j];
    if (curr == numeric_limits<int>::min() || (curr <= v && l != 0)) return l;

    matrix[i][j] = numeric_limits<int>::min();
    int up, down, left, right;
    up    = longestIncreasingPathHelper(matrix, i - 1, j, m, n, curr, l + 1);
    down  = longestIncreasingPathHelper(matrix, i + 1, j, m, n, curr, l + 1);
    left  = longestIncreasingPathHelper(matrix, i, j - 1, m, n, curr, l + 1);
    right = longestIncreasingPathHelper(matrix, i, j + 1, m, n, curr, l + 1);
    matrix[i][j] = curr;

    return max(up, max(down, max(left, right)));
  }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int m = matrix.size();
      if (m <= 0) return 0;

      int n = matrix[0].size(), longest = 0;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          longest = max(longest, longestIncreasingPathHelper(matrix, i, j, m, n, numeric_limits<int>::min(), 0));
        }
      }

      return longest;
    }
};

#endif /* !SOLUTION_H */
