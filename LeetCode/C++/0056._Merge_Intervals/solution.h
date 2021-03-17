/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <algorithm>
using std::min;
using std::max;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res{};
    sort(intervals.begin(), intervals.end(), [](const auto& i1, const auto& i2){
        return i1[0] < i2[0];
    });
    for (const auto& i : intervals) {
      if (res.empty() || res.back()[1] < i[1]) {
        res.push_back(i);
      } else {
        res.back()[1] = max(res.back()[1], i[1]);
      }
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

