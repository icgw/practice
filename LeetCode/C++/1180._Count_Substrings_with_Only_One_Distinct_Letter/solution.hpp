/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
using std::string;

class Solution {
public:
  int countLetters(string S) {
    if (S.empty()) return 0;
    char pre = '\0';
    long cnt = 0, res = 0;
    for (char ch : S) {
      if (ch != pre) {
        res += (cnt * (cnt + 1) / 2);
        pre = ch;
        cnt = 0;
      }
      cnt++;
    }
    res += (cnt * (cnt + 1) / 2);
    return static_cast<int>(res);
  }
};

#endif // ifndef _SOLUTION_HPP_
