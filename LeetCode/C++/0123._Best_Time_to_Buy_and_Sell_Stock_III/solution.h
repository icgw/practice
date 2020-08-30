/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <limits>

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int firstBuy = std::numeric_limits<int>::min(), secondBuy = std::numeric_limits<int>::min();
    int firstSell = 0, secondSell = 0;

    for (int p : prices) {
      secondSell = max(secondSell, secondBuy + p);
      secondBuy  = max(secondBuy, firstSell - p);
      firstSell  = max(firstSell, firstBuy + p);
      firstBuy   = max(firstBuy, -p);
    }

    return secondSell;
  }
};

#endif /* !_SOLUTION_H_ */

