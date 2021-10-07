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
#include <algorithm>
using std::max;
#include <vector>
using std::vector;

class Solution {
private:
  int longest_common(const string& word1, const string& word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1])});
      }
    }
    return dp[m][n];
  }

public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    return m + n - 2 * longest_common(word1, word2);
  }
};

#endif /* !_SOLUTION_H_ */

