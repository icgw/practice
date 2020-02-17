/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

class Solution {
private:
  int countNegatives(vector<int>& v) {
    int sz = v.size();
    int lo = 0, hi = sz - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (v[mid] >= 0) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return sz - lo;
  }

public:
  int countNegatives(vector<vector<int>>& grid) {
    int cnt = 0;
    for (auto &v : grid) {
      cnt += countNegatives(v);
    }
    return cnt;
  }
};

#endif /* !SOLUTION_H */
