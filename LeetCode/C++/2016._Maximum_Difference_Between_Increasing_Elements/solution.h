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
  int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return -1;
    }
    int minVal = nums[0];
    int res = -1;
    for (int i = 1; i < n; ++i) {
      res = max(res, nums[i] - minVal);
      minVal = min(minVal, nums[i]);
    }
    return res <= 0 ? -1 : res;
  }
};

#endif /* !_SOLUTION_H_ */

