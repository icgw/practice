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
using std::max;

class Solution {
private:
  int quickForCornerCase(int len, vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < len; ++i) {
      if (prices[i + 1] > prices[i]) profit += (prices[i + 1] - prices[i]);
    }
    return profit;
  }

public:
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if (k > len / 2 + 1) return quickForCornerCase(len, prices);

    vector<int> dpSell (k + 1, 0);
    vector<int> dpBuy (k + 1, numeric_limits<int>::min());

    for (int p : prices) {
      for (int i = k; i > 0; --i) {
        dpSell[i] = max(dpSell[i], dpBuy[i] + p);
        dpBuy[i] = max(dpBuy[i], dpSell[i - 1] - p);
      }
    }

    return dpSell[k];
  }
};

#endif /* !_SOLUTION_H_ */

