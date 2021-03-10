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
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) return mid;
      if (nums[0] <= nums[mid]) {
        (nums[0] <= target && target < nums[mid]) ? (hi = mid - 1) : (lo = mid + 1);
      } else {
        (nums[mid] < target && target <= nums[n - 1]) ? (lo = mid + 1) : (hi = mid - 1);
      }
    }
    return -1;
  }
};

#endif /* !_SOLUTION_H_ */

