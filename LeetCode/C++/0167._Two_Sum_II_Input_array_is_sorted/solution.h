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
    vector<int> twoSum(vector<int>& numbers, int target) {
      int lo = 0, hi = numbers.size() - 1;
      while (lo < hi) {
        int t = numbers[lo] + numbers[hi];
        if (t == target) {
          return {lo + 1, hi + 1};
        }
        if (t < target) {
          ++lo;
        }
        if (t > target) {
          --hi;
        }
      }
      return {};
    }
};

#endif /* !_SOLUTION_H_ */

