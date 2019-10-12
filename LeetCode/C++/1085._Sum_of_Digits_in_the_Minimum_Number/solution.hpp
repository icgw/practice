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
  int sumOfDigits(vector<int>& A) {
    int n = A.size();
    if (n <= 0) return 1;
    int minOfA = A[0];
    for (int i = 1; i < n; ++i) {
      if (A[i] < minOfA) minOfA = A[i];
    }
    int S = 0;
    while (minOfA != 0) {
      S += (minOfA % 10);
      minOfA /= 10;
    }
    return S % 2 == 1 ? 0 : 1;
  }
};

#endif // ifndef _SOLUTION_HPP_
