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
private:
  vector<vector<int>> kSum(const vector<int>& nums, const int target, const int k, const int start_idx) {
    int n = nums.size();
    if (start_idx < 0 || start_idx > n - k || k < 2) {
      return {};
    }
    vector<vector<int>> res;
    if (k == 2) {
      int lo = start_idx, hi = n - 1;
      while (lo < hi) {
        int two_sum = nums[lo] + nums[hi];
        if (two_sum < target) {
          ++lo;
        } else if (two_sum > target) {
          --hi;
        } else {
          vector<int> r{nums[lo], nums[hi]};
          res.push_back(r);
          while (lo < hi && nums[lo] == r[0]) ++lo;
          while (lo < hi && nums[hi] == r[1]) --hi;
        }
      }
    } else {
      for (int i = start_idx; i <= n - k; ++i) {
        int t = nums[i];
        auto temp = kSum(nums, target - t, k - 1, i + 1);
        for (auto& r : temp) {
          r.insert(r.begin(), t);
        }
        std::copy(temp.begin(), temp.end(), std::back_inserter(res));
        while (i + 1 < n && nums[i + 1] == t) ++i;
      }
    }
    return res;
  }
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    return kSum(nums, target, 4, 0);
  }
};

#endif /* !_SOLUTION_H_ */

