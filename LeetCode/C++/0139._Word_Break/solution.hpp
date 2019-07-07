/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <string>
#include <unordered_set>
using std::string;
using std::vector;
using std::unordered_set;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    int min_len = n, max_len = 0;
    unordered_set<string> wordSet;
    for (auto &w : wordDict) {
      wordSet.insert(w);
      if (min_len > w.size()) min_len = w.size();
      if (max_len < w.size()) max_len = w.size();
    }

    vector<bool> dp (n + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      if (dp[i]) {
        for (int len = min_len; len <= max_len && i + len <= n; ++len) {
          if (wordSet.find(s.substr(i, len)) != wordSet.end()) {
            dp[i + len] = true;
          }
        }
      }
      if (dp[n]) return true;
    }

    return dp[n];
  }
};

#endif // ifndef _SOLUTION_HPP_
