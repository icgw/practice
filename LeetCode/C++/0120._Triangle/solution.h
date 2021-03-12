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
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp(triangle.back());
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};

#endif /* !_SOLUTION_H_ */

