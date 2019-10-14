/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <algorithm>
using std::equal_range;

#include <iterator>
using std::distance;

class Solution {
public:
  bool isMajorityElement(vector<int>& nums, int target) {
    auto eqrange = equal_range(nums.begin(), nums.end(), target);
    return distance(eqrange.first, eqrange.second) > (nums.size() >> 1);
  }
};

#endif // ifndef _SOLUTION_HPP_
