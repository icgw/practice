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
#include <algorithm>
using std::swap;

class Solution {
private:
  void backtrace(vector<vector<int>>& res, vector<int>& output, int start, int len) {
    if (start == len) {
      res.emplace_back(output);
      return;
    }
    for (int i = start; i < len; ++i) {
      swap(output[start], output[i]);
      backtrace(res, output, start + 1, len);
      swap(output[start], output[i]);
    }
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res{};
    backtrace(res, nums, 0, nums.size());
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

