/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
using std::string;

class Solution {
public:
    string removeOuterParentheses(string S) {
      int opened = 0;
      string res = "";
      for (auto ch : S) {
        if (ch == '(' && opened++ > 0) {
          res += ch;
        }
        else if (ch == ')' && opened-- > 1) {
          res += ch;
        }
      }
      return res;
    }
};

#endif // ifndef _SOLUTION_HPP_
