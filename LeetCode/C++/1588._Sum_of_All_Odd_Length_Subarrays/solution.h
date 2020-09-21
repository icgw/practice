/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;

class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    for (int i = 0; i < n; ++i) {
      int t = arr[i];
      s += t;
      for (int j = i; j < n - 2; j += 2) {
        t += (arr[j + 1] + arr[j + 2]);
        s += t;
      }
    }
    return s;
  }
};

#endif /* !_SOLUTION_H_ */

