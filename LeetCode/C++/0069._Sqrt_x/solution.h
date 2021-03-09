/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

class Solution {
public:
  int mySqrt(int x) {
    int lo = 1, hi = x;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (mid > x / mid) {
        hi = mid - 1;
      } else {
        if (mid + 1 > x / (mid + 1)) {
          return mid;
        }
        lo = mid + 1;
      }
    }
    return lo;
  }
};


#endif /* !_SOLUTION_H_ */

