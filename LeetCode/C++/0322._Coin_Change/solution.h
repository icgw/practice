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
using std::min;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount){
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (auto& c : coins){
      for (int i = c; i <= amount; ++i){
          dp[i] = min(dp[i], dp[i - c] + 1);
      }
    }
    return dp[amount] > amount ? - 1 : dp[amount];
  }
};

#endif /* !_SOLUTION_H_ */

