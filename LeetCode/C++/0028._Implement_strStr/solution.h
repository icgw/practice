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

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    int n = haystack.size();
    int m = needle.size();
    for (int i = 0; i < n - m + 1; ++i) {
      for (int j = 0; j < m; ++j) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
        if (j == m - 1) {
          return i;
        }
      }
    }
    return -1;
  }
};

#endif /* !_SOLUTION_H_ */

