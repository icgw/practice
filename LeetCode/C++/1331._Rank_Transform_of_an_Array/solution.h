/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <map>
using std::map;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    if (arr.size() == 0) return { };
    vector<int> sorted_arr = vector<int>(arr);
    sort(sorted_arr.begin(), sorted_arr.end());

    map<int, int> m;
    int n = arr.size();
    int prev = sorted_arr[0] - 1;
    for (int i = 0, j = 1; i < n ; ++i) {
      int a = sorted_arr[i];
      if (a == prev) continue;

      m[a] = j++;
      prev = a;
    }

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      res[i] = m[arr[i]];
    }

    return res;
  }
};

#endif /* !SOLUTION_H */
