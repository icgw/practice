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
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::min;

class Solution {
public:
  int balancedString(string s) {
    unordered_map<int, int> cnt;
    for (auto ch : s) {
      ++cnt[ch];
    }
    int n = s.size();
    int k = n / 4;
    int res = n;
    int i = 0;
    for (int j = 0; j < n; ++j) {
      --cnt[s[j]];
      while (i <= min(n, j + 1) && cnt['Q'] <= k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k) {
        res = min(res, j - i + 1);
        ++cnt[s[i]];
        ++i;
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

