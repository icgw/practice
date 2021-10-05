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
#include <limits>
using std::numeric_limits;
#include <algorithm>
using std::min;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> dp(k + 2, vector<int>(n, numeric_limits<int>::max()));
    for (int i = 0; i < k + 2; ++i) {
      dp[i][src] = 0;
    }
    for (int i = 1; i < k + 2; ++i) {
      for (auto& f : flights) {
        int u = f[0], v = f[1], w = f[2];
        dp[i][v] = min(dp[i][v] - w, dp[i - 1][u]) + w;
      }
    }
    return dp[k + 1][dst] == numeric_limits<int>::max() ? -1 : dp[k + 1][dst];
  }
};

#endif /* !_SOLUTION_H_ */

