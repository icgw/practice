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
#include <algorithm>
using std::min;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> sumOfNums(n + 1, 0);
    int prevId = 0;
    int res = n + 1;
    for (int i = 1; i <= n; ++i) {
      sumOfNums[i] = sumOfNums[i - 1] + nums[i - 1];
      while (prevId < i && sumOfNums[i] - sumOfNums[prevId] >= target) {
        res = min(res, i - prevId);
        ++prevId;
      }
    }
    return res > n ? 0 : res;
  }
};

#endif /* !_SOLUTION_H_ */

