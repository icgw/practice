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
using std::max;
using std::min;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    int i = 0, j = 0;
    vector<vector<int>> res{};
    while (i < firstList.size() && j < secondList.size()) {
      int l = max(firstList[i][0], secondList[j][0]);
      int r = min(firstList[i][1], secondList[j][1]);
      if (l <= r) {
        res.push_back({l, r});
      }
      firstList[i][1] <= secondList[j][1] ? (++i) : (++j);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

