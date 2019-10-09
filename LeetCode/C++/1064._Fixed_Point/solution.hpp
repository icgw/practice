/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class Solution {
public:
  int fixedPoint(vector<int>& A) {
    int lo = 0, hi = A.size() - 1;
    while (lo <= hi) {
      if (A[lo] == lo) return lo;

      int mid = lo + (hi - lo) / 2;
      if (A[mid] > mid) {
        hi = mid - 1;
      }
      else if (A[mid] < mid) {
        lo = mid + 1;
      }
      else { // A[mid] == mid
        ++lo;
        hi = mid;
      }
    }
    return -1;
  }
};

#endif // ifndef _SOLUTION_HPP_
