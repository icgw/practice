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
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; ++i) {
      for (int k = 1; k * k <= i; ++k) {
        if (!dp[i - k * k]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};

#endif /* !_SOLUTION_H_ */

