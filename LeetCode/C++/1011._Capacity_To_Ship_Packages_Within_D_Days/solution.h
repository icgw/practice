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
  int shipWithinDays(vector<int>& weights, int D) {
    int lo = 0, hi = 0;
    for (int w : weights) {
      lo = max(lo, w);
      hi += w;
    }
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int cur = 0;
      int need = 1;
      for (int w : weights) {
        if (cur + w > mid) {
          ++need;
          cur = 0;
        }
        cur += w;
      }
      if (need > D) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};

#endif /* !_SOLUTION_H_ */

