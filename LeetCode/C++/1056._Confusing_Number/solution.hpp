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

#include <algorithm>
using std::reverse;

class Solution {
public:
  bool confusingNumber(int N) {
    static int m[10] = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };
    string s1 = to_string(N), s2 = "";
    reverse(begin(s1), end(s1));
    int M = 0, curr;
    for (char ch : s1) {
      curr = m[ch - '0'];
      if (curr == -1) return false;
      M = M * 10 + curr;
    }
    return M != N;
  }
};

#endif // ifndef _SOLUTION_HPP_
