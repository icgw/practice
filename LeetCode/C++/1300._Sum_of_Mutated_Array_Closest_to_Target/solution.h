/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;

class Solution {
public:
  int findBestValue(vector<int>& arr, int target) {
    int n = arr.size();
    if (n == 0) return 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
      double average = static_cast<double>(target) / (n - i);
      if (static_cast<double>(arr[i]) >= average) {
        return static_cast<int>(average + (0.5 - 1e-9));
      }
      target -= arr[i];
    }
    return arr[n - 1];
  }
};

#endif /* !_SOLUTION_H_ */

