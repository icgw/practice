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

class Solution {
public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    if (mat.empty()) return 0;
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    int len = 1;
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
        if (i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= threshold) {
          res = len++;
        }
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

