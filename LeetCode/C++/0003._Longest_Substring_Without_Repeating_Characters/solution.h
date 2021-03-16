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
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::max;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> lookup;
    int left = 0;
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      while (lookup.find(s[i]) != lookup.end()) {
        lookup.erase(s[left]);
        ++left;
      }
      lookup.insert(s[i]);
      res = max(res, i - left + 1);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

