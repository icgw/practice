/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <unordered_map>
using std::unordered_map;

#include <string>
using std::string;

class Solution {
private:
  unordered_map<string, long> memo = { };

  int dp(string s, string t) {
    if (memo.find(s) != memo.end()) return memo[s];

    int sn = s.size(), tn = t.size();

    if (sn <= tn) {
      memo[s] = (s == t) ? 1 : 0;
      return memo[s];
    }

    memo[s] = 0;
    for (int i = 0, n = s.size(); i < n; ++i) {
      string tmp = s;
      tmp.erase(i, 1);
      memo[s] += dp(tmp, t);
    }

    return memo[s];
  }
public:
  int numDistinct(string s, string t) {
    memo.clear();
    dp(s, t);

    int m = s.size() - t.size();
    long div = 1;
    for (int i = 2; i <= m; ++i) div *= i;

    return memo[s] / div;
  }
};

#endif /* !_SOLUTION_H_ */

