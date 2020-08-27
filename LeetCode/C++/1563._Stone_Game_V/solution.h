/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <algorithm>
#include <vector>

using std::vector;
using std::max;

class Solution {
private:
  vector<int> prefixSum    = { };
  vector<vector<int>> memo = { };

  int dp(vector<int>& stoneValue, int lo, int hi) {
    if (lo >= hi) return 0;

    if (-1 != memo[lo][hi]) return memo[lo][hi];

    for (int i = lo; i <= hi; ++i) {
      int l = prefixSum[i] - prefixSum[lo], r = prefixSum[hi] - prefixSum[i];

      if (l <= r) {
        memo[lo][hi] = max(memo[lo][hi], dp(stoneValue, lo, i) + l);
      }

      if (r <= l) {
        memo[lo][hi] = max(memo[lo][hi], dp(stoneValue, i, hi) + r);
      }
    }

    return memo[lo][hi];
  }

public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();

    prefixSum.resize(n + 1, 0);

    for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + stoneValue[i];

    memo.resize(n + 1, vector<int>(n + 1, -1));

    return dp(stoneValue, 0, n);
  }
};

#endif /* !_SOLUTION_H_ */

