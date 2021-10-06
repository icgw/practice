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
using std::max;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      res += max(prices[i] - prices[i - 1], 0);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

