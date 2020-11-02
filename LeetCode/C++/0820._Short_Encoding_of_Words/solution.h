/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;

class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    for (auto& w : words) {
      reverse(begin(w), end(w));
    }
    sort(begin(words), end(words), [](const string& l, const string& r) {
            return l < r;
        });
    int cnt = 0;
    string prev = "";
    for (int i = 0, n = words.size(); i < n;) {
      while (i < n && words[i].find(prev) == 0) {
        prev = words[i];
        ++i;
      }
      cnt += (prev.size() + 1);
      prev = "";
    }
    return cnt;
  }
};

#endif /* !_SOLUTION_H_ */

