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
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> zigzag(numRows, "");
    int n = s.size();
    int i = 0;
    while (i < n) {
      for (int j = 0; j < numRows && i < n; ++j) {
        zigzag[j] += s[i++];
      }
      for (int j = numRows - 2; j > 0 && i < n; --j) {
        zigzag[j] += s[i++];
      }
    }
    string ans{""};
    for (auto& z : zigzag) {
      ans += z;
    }
    return ans;
  }
};

#endif /* !_SOLUTION_H_ */

