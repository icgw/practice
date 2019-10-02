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
using std::to_string;

#include <cmath>
using std::pow;

class Solution {
public:
  bool isArmstrong(int N) {
    string s = to_string(N);
    int sz = s.size();
    int sum = 0;
    for (char ch : s) {
      sum += pow(ch - '0', sz);
    }
    return sum == N;
  }
};

#endif // ifndef _SOLUTION_HPP_
