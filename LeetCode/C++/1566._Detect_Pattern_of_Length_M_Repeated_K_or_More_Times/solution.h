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
private:
  bool containPattern(vector<int>& arr, int start, int m, int k) {
    bool flag = true;
    for (int i = start; i < start + m; ++i) {
      for (int j = 1; j < k; ++j) {
        flag &= (arr[i] == arr[i + j * m]);
      }
    }
    return flag;
  }
public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    int n = arr.size();
    for (int i = 0; i <= n - k * m; ++i) {
      if (containPattern(arr, i, m, k)) return true;
    }
    return false;
  }
};

#endif /* !_SOLUTION_H_ */

