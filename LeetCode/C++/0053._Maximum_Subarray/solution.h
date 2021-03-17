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
  struct Status {
    int LSum, RSum, MSum, ISum;
  };

  Status pushUp(const Status& l, const Status& r) {
    int lsum = max(l.LSum, l.ISum + r.LSum);
    int rsum = max(r.RSum, r.ISum + l.RSum);
    int msum = max(l.MSum, r.MSum);
    msum = max(msum, l.RSum + r.LSum);
    int isum = l.ISum + r.ISum;
    return {lsum, rsum, msum, isum};
  }

  Status get(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return {nums[l], nums[l], nums[l], nums[l]};
    }
    int m = l + (r - l) / 2;
    Status s1 = get(nums, l, m);
    Status s2 = get(nums, m + 1, r);
    return pushUp(s1, s2);
  }
public:
  int maxSubArray(vector<int>& nums) {
    Status s = get(nums, 0, nums.size() - 1);
    return s.MSum;
  }
};

#endif /* !_SOLUTION_H_ */

