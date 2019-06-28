/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& A) {
    int lo = 0, hi = A.size() - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (A[mid] < A[mid + 1])
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }
};

#endif // ifndef _SOLUTION_HPP_
