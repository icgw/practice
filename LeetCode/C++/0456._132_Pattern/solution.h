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
#include <stack>
using std::stack;
#include <numeric>
using std::numeric_limits;

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return false;
    }
    stack<int> stk{};
    int k = numeric_limits<int>::min();
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] < k) {
        return true;
      }
      while (!stk.empty() && nums[i] > stk.top()) {
        k = stk.top();
        stk.pop();
      }
      if (nums[i] > k) {
        stk.push(nums[i]);
      }
    }
    return false;
  }
};

#endif /* !_SOLUTION_H_ */

