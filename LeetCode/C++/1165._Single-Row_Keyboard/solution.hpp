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

#include <cmath>
using std::abs;

class Solution {
public:
  int calculateTime(string keyboard, string word) {
    int m[26];
    for (int i = 0; i < 26; ++i) {
      m[keyboard[i] - 'a'] = i;
    }
    int prev = keyboard[0] - 'a';
    int res = 0;
    for (char ch : word) {
      res += abs(m[prev] - m[ch - 'a']);
      prev = ch - 'a';
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
