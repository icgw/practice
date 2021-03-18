/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
private:
  void backtrace(vector<string>& res, string cur, int lparens, int rparens, int n) {
    if (cur.size() == 2 * n) {
      res.push_back(cur);
      return;
    }
    if (lparens < n) {
      backtrace(res, cur + "(", lparens + 1, rparens, n);
    }
    if (lparens > rparens) {
      backtrace(res, cur + ")", lparens, rparens + 1, n);
    }
    return;
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res{};
    backtrace(res, "", 0, 0, n);
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

