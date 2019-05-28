/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> nums = heights;
    sort(nums.begin(), nums.end());
    int n = heights.size(), cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (heights[i] != nums[i]) ++cnt;
    }
    return cnt;
  }
};

#endif // ifndef _SOLUTION_HPP_
