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
#include <algorithm>
using std::reverse;

class Solution {
public:
  string convertToTile(int columnNumber) {
    int r;
    string ans;
    while (columnNumber > 0) {
      r = --columnNumber % 26;
      ans += ('A' + r);
      columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

#endif /* !_SOLUTION_H_ */
