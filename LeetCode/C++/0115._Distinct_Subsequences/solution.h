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
    vector<vector<long>> dp (tn + 1, vector<long>(sn + 1, 0));
    for (int j = 0; j <= sn; ++j) dp[0][j] = 1;

    for (int j = 1; j <= sn; ++j) {
      for (int i = 1; i <= tn; ++i) {
        dp[i][j] = dp[i][j - 1] + ((t[i - 1] == s[j - 1]) ? dp[i - 1][j - 1] : 0);
      }
    }

    return dp[tn][sn];
  }
};

#endif /* !_SOLUTION_H_ */

