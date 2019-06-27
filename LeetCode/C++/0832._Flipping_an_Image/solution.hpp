/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto &v : A) {
      reverse(v.begin(), v.end());
      for (auto &e : v) {
        e = 1 - e;
      }
    }
    return A;
  }
};

#endif // ifndef _SOLUTION_HPP_
