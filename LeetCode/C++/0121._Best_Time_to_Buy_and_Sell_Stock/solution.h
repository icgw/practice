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
using std::min;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy_price = prices[0];
    int max_profit = 0;
    for (int p : prices) {
      max_profit = max(max_profit, p - buy_price);
      buy_price = min(buy_price, p);
    }
    return max_profit;
  }
};

#endif /* !_SOLUTION_H_ */

