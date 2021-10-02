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
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::sort;

class Solution {
public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> built;
    string res = "";
    for (auto& w : words) {
      if (w.size() == 1 || built.find(w.substr(0, w.size() - 1)) != built.end()) {
        res = (res.size() < w.size()) ? w : res;
        built.insert(w);
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

