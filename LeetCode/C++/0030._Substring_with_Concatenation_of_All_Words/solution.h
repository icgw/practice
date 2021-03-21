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
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> counts{};
    for (auto& w : words) {
      counts[w]++;
    }
    int len = words[0].size();
    int numOfWords = words.size();
    vector<int> res{};
    int n = s.size();
    for (int i = 0; i < n - len * numOfWords + 1; ++i) {
      unordered_map<string, int> seen{};
      int j = 0;
      for ( ; j < numOfWords; ++j) {
        string sub = s.substr(i + j * len, len);
        if (counts.find(sub) != counts.end() && seen[sub] < counts[sub]) {
          seen[sub]++;
        } else {
          break;
        }
      }
      if (j == numOfWords) {
        res.push_back(i);
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

