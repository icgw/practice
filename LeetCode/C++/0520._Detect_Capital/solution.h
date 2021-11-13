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
#include <cctype>
using std::islower;
using std::isupper;

class Solution {
public:
  bool detectCapitalUse(string word) {
    int n = word.size();
    for (int i = 2; i < n; ++i) {
      if (islower(word[1]) ^ islower(word[i])) {
        return false;
      }
    }
    return n < 2 || !(islower(word[0]) && isupper(word[1]));
  }
};

#endif /* !_SOLUTION_H_ */

