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
  int largestUniqueNumber(vector<int>& A) {
    short cnt[1001] = { 0 };
    int lo = 1000, hi = 0;
    for (int i : A) {
      ++cnt[i];
      if (i > hi) hi = i;
      if (i < lo) lo = i;
    }
    for (int i = hi; i >= lo; --i) {
      if (cnt[i] == 1) return i;
    }
    return -1;
  }
};

#endif // ifndef _SOLUTION_HPP_
