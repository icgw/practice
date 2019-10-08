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
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      if (A[i] == i) return i;
    }
    return -1;
  }
};

#endif // ifndef _SOLUTION_HPP_
