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
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int num : nums) {
      if (i < 2 || nums[i - 2] != num) {
        nums[i] = num;
        ++i;
      }
    }
    return i;
  }
};

#endif /* !_SOLUTION_H_ */

