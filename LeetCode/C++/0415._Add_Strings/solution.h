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
  string addStrings(string num1, string num2) {
    string ans{""};
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int add = 0;
    while (i >= 0 || j >= 0 || add > 0) {
      int x = (i >= 0) ? num1[i] - '0' : 0;
      int y = (j >= 0) ? num2[j] - '0' : 0;
      int result = x + y + add;
      ans.push_back('0' + result % 10);
      add = result / 10;
      --i, --j;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

#endif /* !_SOLUTION_H_ */

