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
#include <stack>
using std::stack;
#include <unordered_map>
using std::unordered_map;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk{};
    unordered_map<char, char> m{{')', '('}, {']', '['}, {'}', '{'}};
    for (char ch : s) {
      if (stk.empty() || m.find(ch) == m.end()) {
        stk.push(ch);
      } else {
        if (stk.top() != m[ch]) {
          return false;
        }
        stk.pop();
      }
    }
    return stk.empty();
  }
};

#endif /* !_SOLUTION_H_ */

