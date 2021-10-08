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
using std::min;
using std::max;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int lo = 0, hi = height.size() - 1;
    int res = 0;
    while (lo < hi) {
      int left_height = height[lo];
      int right_height = height[hi];
      int h = min(left_height, right_height);
      res = max(res, h * (hi - lo));
      while (lo < hi && height[lo] <= h) {
        ++lo;
      }
      while (lo < hi && height[hi] <= h) {
        --hi;
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

