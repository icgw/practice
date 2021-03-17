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
  int maxScoreSightseeingPair(vector<int>& values) {
    int mx = values[0] + 0;
    int res = 0;
    for (int i = 1; i < values.size(); ++i) {
      res = max(res, mx + values[i] - i);
      mx = max(mx, values[i] + i);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

