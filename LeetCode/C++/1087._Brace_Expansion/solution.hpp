/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

#include <unordered_map>
using std::unordered_map;

class Solution {
private:
  vector<string> helper(vector<string> opts, int i, unordered_map<int, vector<string>> &memo) {
    vector<string> res;

    if (i + 1 == opts.size()) {
      for (char ch : opts[i]) {
        res.push_back( string(1, ch) );
      }
      return res;
    }

    if (memo.find(i) != memo.end()) {
      return memo[i];
    }

    vector<string> tails = helper(opts, i + 1, memo);
    for (char ch : opts[i]) {
      for (string t : tails) {
        res.push_back( string(1, ch) + t );
      }
    }

    memo[i] = res;
    return res;
  }

public:
  vector<string> expand(string S) {
    vector<string> opt, res;

    for (int i = 0, n = S.size(); i < n; ++i) {
      string s = "";
      if (S[i] == '{') {
        ++i;
        while (i < n && S[i] != '}') {
          if (S[i] != ',') {
            s += S[i];
          }
          ++i;
        }
      } else {
        s = string(1, S[i]);
      }
      opt.push_back(s);
    }

    unordered_map<int, vector<string>> memo;
    res = helper(opt, 0, memo);

    sort(begin(res), end(res));
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
