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
  int specialArray(vector<int>& nums) {
    vector<int> v(102, 0);
    for (auto n : nums) {
      ++v[(n > 100) ? 100 : n];
    }
    for (int i = 100; i > 0; --i) {
      v[i] += v[i + 1];
      if (i == v[i]) {
        return i;
      }
    }
    return -1;
  }
};

#endif /* !_SOLUTION_H_ */

