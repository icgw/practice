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
#include <set>
using std::set;
#include <algorithm>
using std::max;

class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    set<int> xs{};
    for (auto& p : points)
      xs.insert(p[0]);
    int res = 0;
    for (auto it = next(begin(xs)); it != end(xs); ++it)
      res = max(res, *it - *prev(it));
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

