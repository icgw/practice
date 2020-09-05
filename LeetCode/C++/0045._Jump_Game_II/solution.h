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

#include <algorithm>
using std::max;

class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();

    int jumps = 0, end = 0, nextEnd = 0;

    for (int i = 0; i <= end && end < n - 1; ++i) {
      nextEnd = max(nextEnd, i + nums[i]);

      if (i == end) {
        ++jumps;
        end = nextEnd;
      }
    }

    return jumps;
  }
};

#endif /* !_SOLUTION_H_ */

