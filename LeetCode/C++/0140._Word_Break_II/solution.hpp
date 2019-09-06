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
using std::vector;
using std::string;
using std::function;

#include <unordered_set>
using std::unordered_set;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    // NOTE: transform vector into set.
    unordered_set<string> wd(wordDict.begin(), wordDict.end());

    // NOTE: initial the vector with empty string.
    unordered_map<int, vector<string>> memo { { s.size(), {""} } };

    // NOTE: DFS with a memo that store the previous result.
    function<vector<string>(int)> sentences = [&](int i) {
      if (!memo.count(i))
        for (int j = i + 1; j <= s.size(); ++j)
          if (wd.count(s.substr(i, j - i)))
            for (string tail : sentences(j))
              memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : " " + tail));
      return memo[i];
    };

    return sentences(0);
  }

  // vector<string> helper(string s, int sz, int start, unordered_set<string>& wordDict, unordered_map<int, vector<string>>& memo) {
  //   if (memo.find(start) == memo.end()) {
  //     for (int i = start + 1; i <= sz; ++i) {
  //       if (wordDict.find(s.substr(start, i - start)) != wordDict.end()) {
  //         for (string tail : helper(s, sz, i, wordDict, memo)) {
  //           memo[start].push_back(s.substr(start, i - start) + (tail == "" ? "" : (" " + tail)));
  //         }
  //       }
  //     }
  //   }
  //   return memo[start];
  // }

  // vector<string> wordBreak(string s, vector<string>& wordDict) {
  //   unordered_set<string> sWordDict (wordDict.begin(), wordDict.end());
  //   unordered_map<int, vector<string>> memo { { s.size(), {""} } };
  //   int n = s.size();
  //   return helper(s, n, 0, sWordDict, memo);
  // }
};

#endif // ifndef _SOLUTION_HPP_
