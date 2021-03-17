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
#include <string>
using std::string;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans{""};
    for (int len = 0; len < n; ++len) {
      for (int i = 0; i + len < n; ++i) {
        if (len == 0) {
          dp[i][i] = 1;
        }
        else if (len == 1) {
          dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        else {
          int j = i + len;
          dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
        }
        if (dp[i][i + len] == 1 && len >= ans.size()) {
          ans = s.substr(i, len + 1);
        }
      }
    }
    return ans;
  }
};

#endif /* !_SOLUTION_H_ */

