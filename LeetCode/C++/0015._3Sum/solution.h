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
using std::sort;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      if (target < 0) {
        break;
      }

      int lo = i + 1;
      int hi = nums.size() - 1;

      while (lo < hi) {
        int n1 = nums[lo];
        int n2 = nums[hi];
        int sum = n1 + n2;
        if (sum < target) {
          ++lo;
        }
        else if (sum > target) {
          --hi;
        }
        else {
          res.push_back( { -target, n1, n2 } );
          while (lo < hi && nums[lo] == n1) {
            ++lo;
          }
          while (lo < hi && nums[hi] == n2) {
            --hi;
          }
        }
      }

      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        ++i;
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

