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
private:
  vector<int> get_max_num_of_eq_pref_suf_str(const string& s) {
    int m = s.size();
    vector<int> max_eq_pref_suff(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
      while (j > 0 && s[i] != s[j]) {
        j = max_eq_pref_suff[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      max_eq_pref_suff[i] = j;
    }
    return max_eq_pref_suff;
  }
public:
  int strStr(string haystack, string needle) {
    int m = needle.size();
    if (m == 0) {
      return 0;
    }
    auto lps = get_max_num_of_eq_pref_suf_str(needle);
    int n = haystack.size();
    for (int i = 0, j = 0; i < n; ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = lps[j - 1];
      }
      if (haystack[i] == needle[j]) {
        ++j;
      }
      if (j == m) {
        return (i - m + 1);
      }
    }
    return -1;
  }
};

#endif /* !_SOLUTION_H_ */

