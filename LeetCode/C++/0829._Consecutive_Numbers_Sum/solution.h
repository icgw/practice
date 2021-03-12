/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <cmath>
using std::sqrt;

class Solution {
public:
  int consecutiveNumbersSum(int N) {
    // N = (x + 1) + (x + 2) + ... + (x + k)
    // N - k * (k + 1) / 2 = k * x
    // 2N = k * (k + x + 1)
    int res = 0;
    for (int k = 1; k < sqrt(N + N); ++k) {
      if ((N - k * (k + 1) / 2) % k == 0)
        ++res;
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

