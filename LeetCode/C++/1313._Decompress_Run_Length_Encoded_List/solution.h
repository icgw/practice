/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

class Solution {
public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0, j = 1; j < n; i += 2, j += 2) {
      for (int k = 0; k < nums[i]; ++k) {
        res.push_back(nums[j]);
      }
    }
    return res;
  }
};

#endif /* !SOLUTION_H */
