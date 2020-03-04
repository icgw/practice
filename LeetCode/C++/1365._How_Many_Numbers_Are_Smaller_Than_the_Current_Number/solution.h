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

#include <utility>
using std::pair;

#include <algorithm>
using std::sort;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    if (n < 1) return { };

    vector<pair<int, int>> pairs (n);
    for (int i = 0; i < n; ++i) {
      pairs[i].first = nums[i];
      pairs[i].second = i;
    }

    sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b) {
          return a.first < b.first;
        });

    vector<int> res (n, 0);
    for (int i = 1, prev = pairs[0].first, k = 0; i < n; ++i) {
      if (pairs[i].first == prev) {
        res[pairs[i].second] = k;
      } else {
        res[pairs[i].second] = i;
        prev = pairs[i].first;
        k = i;
      }
    }

    return res;
  }
};

#endif /* !SOLUTION_H */
