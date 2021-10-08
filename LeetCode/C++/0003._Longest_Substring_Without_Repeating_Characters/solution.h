/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> lookup(256, -1);
    int left = -1;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (lookup[s[i]] > left) {
        left = lookup[s[i]];
      }
      lookup[s[i]] = i;
      res = max(res, i - left);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

