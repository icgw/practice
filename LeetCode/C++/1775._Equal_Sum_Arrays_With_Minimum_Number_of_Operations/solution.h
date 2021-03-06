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
#include <numeric>
using std::accumulate;
#include <algorithm>
using std::max;

class Solution {
public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size() * 6 || nums1.size() * 6 < nums2.size()) {
      return -1;
    }
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    if (sum1 > sum2) { // guarantee the sum of nums1 is less than nums2.
      return minOperations(nums2, nums1);
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int diff = sum2 - sum1;
    int lo = 0, hi = nums2.size() - 1;
    int op = 0;
    while (diff > 0) {
      int increase = ((lo < nums1.size()) ? (6 - nums1[lo]) : 0);
      int decrease = ((hi >= 0) ? (nums2[hi] - 1) : 0);
      int d = max(increase, decrease);
      ++op;
      if (d >= diff) {
        return op;
      }
      diff -= d;
      if (increase > decrease) {
        ++lo;
      } else {
        --hi;
      }
    }
    return op;
  }
};

#endif /* !_SOLUTION_H_ */

