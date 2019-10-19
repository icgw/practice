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

#include <algorithm>
using std::max;
using std::sort;

class Solution {
public:
  int twoSumLessThanK(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int lo = 0, hi = A.size() - 1, res = -1;
    while (lo < hi) {
      int s = A[lo] + A[hi];
      if (s < K) {
        res = max(res, s);
        ++lo;
      } else {
        --hi;
      }
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
