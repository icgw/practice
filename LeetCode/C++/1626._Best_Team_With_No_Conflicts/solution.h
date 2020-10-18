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
#include <numeric>
using std::iota;
#include <algorithm>
using std::max;

class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<int> idx(n, 0);
    iota(begin(idx), end(idx), 0);
    auto cmp = [&](const int& l, const int& r) {
      return ages[l] > ages[r] || (ages[l] == ages[r] && scores[l] > scores[r]);
    };
    sort(begin(idx), end(idx), cmp);
    vector<int> dp(n + 1, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      dp[i] = scores[idx[i]];
      for (int j = 0; j < i; ++j) {
        if (scores[idx[j]] >= scores[idx[i]]) {
          dp[i] = max(dp[i], dp[j] + scores[idx[i]]);
        }
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

