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
  string removeVowels(string S) {
    string res = "";
    for (char ch : S) {
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
      res.push_back(ch);
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
