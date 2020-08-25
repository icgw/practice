/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::greater;

class Solution {
public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end(), greater<int>());
    int res = 0;
    for (int i = 1, n = piles.size() / 3 * 2; i < n;
         res += piles[i], i += 2);
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

