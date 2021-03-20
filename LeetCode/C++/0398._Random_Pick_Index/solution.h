/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <cstdlib>
using std::rand;
#include <vector>
using std::vector;

class Solution {
private:
  vector<int> nums_;
public:
  Solution(vector<int>& nums) : nums_(nums) {}

  int pick(int target) {
    int cnt = 0;
    int index = -1;
    int n = nums_.size();
    for (int i = 0; i < n; ++i) {
      if (nums_[i] == target) {
        ++cnt;
        if (rand() % cnt == 0) {
          index = i;
        }
      }
    }
    return index;
  }
};

#endif /* !_SOLUTION_H_ */

