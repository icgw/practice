/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::max;

class Solution {
public:
  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const auto& l, const auto& r) {
        return l[1] - l[0] < r[1] - r[0];
    });
    int res = 0;
    for (auto &t : tasks) {
      res = max(res + t[0], t[1]);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

