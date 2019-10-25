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
  int missingNumber(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    int d = (arr.back() - arr.front()) / static_cast<int>(arr.size());
    int a0 = arr[0];
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] != a0 + mid * d) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return arr[hi] - d;
  }
};

#endif // ifndef _SOLUTION_HPP_
