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

#include <algorithm>
using std::fill;

#include <iterator>
using std::begin;
using std::end;

class Solution {
public:
  int shortestWay(string source, string target) {
    int sn = source.size(), tn = target.size();

    int startIndex[26];
    fill(begin(startIndex), end(startIndex), -1);

    for (int i = 0; i < sn; ++i) {
      int cInd = source[i] - 'a';
      if (startIndex[cInd] == -1) {
        startIndex[cInd] = i;
      }
    }

    int res = 0;
    for (int i = 0; i < tn; ) {
      int sInd = startIndex[target[i] - 'a'];
      if (-1 == sInd) return -1;

      for (int j = sInd; j < sn; ++j) {
        if (source[j] == target[i]) {
          ++i;
        }
      }

      ++res;
    }

    return res;
  }
};


#endif // ifndef _SOLUTION_HPP_
