/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
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
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();

    vector<vector<int>> dp (m + 1, vector<int>(n + 1, numeric_limits<int>::max()));
    dp[0][1] = dp[1][0] = 1;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) - dungeon[m - i][n - j];
        if (dp[i][j] < 1) dp[i][j] = 1;
      }
    }

    return dp[m][n];
  }
};

#endif /* !_SOLUTION_H_ */

