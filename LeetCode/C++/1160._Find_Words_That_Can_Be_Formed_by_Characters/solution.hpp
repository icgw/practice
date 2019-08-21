/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
public:
  int lenOfGoodString(string w, vector<int> v) {
    for (char ch : w) {
      int idx = ch - 'a';
      v[idx]--;
      if (v[idx] < 0) return 0;
    }
    return w.length();
  }

  int countCharacters(vector<string>& words, string chars) {
    vector<int> count (26, 0);
    for (char ch : chars) {
      count[ ch - 'a' ]++;
    }
    int sum = 0;
    for (string s : words) {
      sum += lenOfGoodString(s, count);
    }
    return sum;
  }
};

#endif // ifndef _SOLUTION_HPP_
