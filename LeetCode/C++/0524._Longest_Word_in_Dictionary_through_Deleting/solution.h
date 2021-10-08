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
#include <vector>
using std::vector;

class Solution {
public:
  string findLongestWord(string s, vector<string>& dictionary) {
    string res = "";
    for (auto& w : dictionary) {
      int i = 0, j = 0;
      while (i < s.size() && j < w.size()) {
        if (s[i] == w[j]) {
          ++j;
        }
        ++i;
      }
      if (j == w.size() && (res.size() < j || (res.size() == j && res > w))) {
        res = w;
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

