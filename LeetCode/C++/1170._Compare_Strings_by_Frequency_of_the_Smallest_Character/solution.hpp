/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
  int f(string s) {
    if (s.empty()) return 0;
    int nums[26] = { 0 };
    for (char c : s) {
      ++nums[c - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (nums[i] > 0) return nums[i];
    }
    return 0;
  }
  
  int countLess(int n, vector<int> ws) {
    int cnt = 0;
    for (int i : ws) {
      if (n < i) {
        ++cnt;
      }
    }
    return cnt;
  }

  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> n_queries, n_words;

    for (string q : queries) {
      n_queries.push_back(f(q));
    }

    for (string w : words) {
      n_words.push_back(f(w));
    }

    vector<int> ans;
    for (int nq : n_queries) {
      ans.push_back(countLess(nq, n_words));
    }

    return ans;
  }
};

#endif // ifndef _SOLUTION_HPP_
