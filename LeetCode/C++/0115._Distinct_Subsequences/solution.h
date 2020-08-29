/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
  int numDistinct(string s, string t) {
    int tn = t.size(), sn = s.size();
    vector<long> dp (tn + 1, 0); dp[0] = 1;

    for (int j = 1; j <= sn; ++j) {
      for (int i = tn; i >= 1; --i) {
        dp[i] = dp[i] + ((t[i - 1] == s[j - 1]) ? dp[i - 1] : 0);
      }
    }

    return dp[tn];
  }
};

#endif /* !_SOLUTION_H_ */

