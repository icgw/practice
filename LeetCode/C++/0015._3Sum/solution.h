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
    vector<vector<int>> res{};
    int previ = nums[0] - 1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == previ) continue;
      int L = i + 1;
      int R = n - 1;
      while (L < R) {
        int sum = nums[i] + nums[L] + nums[R];
        if (sum < 0) {
          ++L;
        } else if (sum > 0) {
          --R;
        } else {
          res.push_back({nums[i], nums[L], nums[R]});
          while (L + 1 < R && nums[L] == nums[L + 1]) ++L;
          while (R - 1 > L && nums[R] == nums[R - 1]) --R;
          ++L, --R;
        }
      }
      previ = nums[i];
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

