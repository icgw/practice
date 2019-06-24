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
using std::count;

class Solution {
public:
  // Brute.
  // void duplicateZeros(vector<int>& arr) {
  //   int sz = arr.size();
  //   if (sz <= 1) return;

  //   for (int i = 1; i < sz; ++i) {
  //     if (arr[i - 1] == 0) {
  //       for (int k = sz - 1; k > i; --k) {
  //         arr[k] = arr[k - 1];
  //       }
  //       arr[i] = 0;
  //       ++i;
  //     }
  //   }
  // }

  void duplicateZeros(vector<int>& arr) {
    int sz = arr.size();
    int j  = sz + count(arr.begin(), arr.end(), 0);
    for (int i = sz - 1; i >= 0; --i) {
      if (--j < sz) {
        arr[j] = arr[i];
      }

      if (arr[i] == 0 && --j < sz) {
        arr[j] = 0;
      }
    }
  }
};

#endif // ifndef _SOLUTION_HPP_
