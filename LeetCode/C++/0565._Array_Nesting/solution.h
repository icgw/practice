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
using std::max;

class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int ans = 0;
    vector<int> seen(nums.size(), 0);
    for (int n : nums) {
      if (seen[n] == 1) continue;
      int cnt = 0;
      while (seen[n] == 0) {
        ++cnt;
        seen[n] = 1;
        n = nums[n];
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};

#endif /* !_SOLUTION_H_ */

