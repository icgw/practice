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
using std::swap;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int sz = A.size();
    int current_even = 0;
    for (int i = 0; i < sz; ++i) {
      if (!(A[i] & 0x1)) {
        swap(A[i], A[current_even++]);
      }
    }
    return A;
  }
};

#endif // ifndef _SOLUTION_HPP_
