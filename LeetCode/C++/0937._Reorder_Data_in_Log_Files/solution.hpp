/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;
using std::stable_sort;

class Solution {
public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    stable_sort(logs.begin(), logs.end(),
        [](string a, string b) -> bool {
          int i = a.find(' '), j = b.find(' ');
          if (!isdigit(a[i + 1]) && !isdigit(b[j + 1])) {
            string suba = a.substr(i + 1), subb = b.substr(j + 1);
            int cmp = suba.compare(subb);
            if (cmp == 0) {
              return a.substr(0, i) < b.substr(0, j);
            }
            return suba < subb;
          } else {
            if (!isdigit(a[i + 1])) {
              return true;
            }
            return false;
          }
        });
    return logs;
  }
};

#endif // ifndef _SOLUTION_HPP_
