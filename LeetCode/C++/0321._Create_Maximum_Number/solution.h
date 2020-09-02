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
using std::min;
using std::max;

class Solution {
private:
  vector<int> maxNumber(vector<int>& nums, int k) {
    int drop = nums.size() - k;
    vector<int> res;
    if (0 == k) return res;

    for (int num : nums) {
      while (drop > 0 && res.size() > 0 && num > res.back()) {
        res.pop_back();
        --drop;
      }
      res.push_back(num);
    }

    res.resize(k);
    return res;
  }

  vector<int> maxNumber(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    int n1 = nums1.size(), n2 = nums2.size();
    while (nums1.size() + nums2.size() > 0) {
      auto& nums = ((nums1 > nums2) ? nums1 : nums2);
      res.push_back(nums[0]);
      nums.erase(nums.begin());
    }

    res.resize(n1 + n2);
    return res;
  }

public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = max(0, k - n2); i <= min(n1, k); ++i) {
      res = max(res, maxNumber(maxNumber(nums1, i), maxNumber(nums2, k - i)));
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

