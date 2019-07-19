/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <algorithm>
#include <vector>
using std::sort;
using std::vector;

class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    static int hash [1001];
    for (auto i : arr1) {
      hash[i] = i + 1000;
    }

    for (int i = 0, sz = arr2.size(); i < sz; ++i) {
      hash[arr2[i]] = i;
    }

    sort(arr1.begin(), arr1.end(), [&](int a, int b) -> bool {
      return hash[a] < hash[b];
    });

    return arr1;
  }
};

#endif // ifndef _SOLUTION_HPP_
