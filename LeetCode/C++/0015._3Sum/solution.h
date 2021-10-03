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
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; ++i) {
      int L = i + 1;
      int R = n - 1;
      int target = -nums[i];
      while (L < R) {
        int two_sum = nums[L] + nums[R];
        if (two_sum < target) {
          ++L;
        } else if (two_sum > target) {
          --R;
        } else {
          vector<int> tri{nums[i], nums[L], nums[R]};
          res.push_back(tri);
          while (L < R && nums[L] == tri[1]) ++L;
          while (L < R && nums[R] == tri[2]) --R;
        }
      }
      while (i < n - 2 && nums[i + 1] + target == 0) ++i;
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

