/*
 * solution.h
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
using std::max;
#include <cmath>
using std::abs;
#include <vector>
using std::vector;

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size(), t = 0;
    if (n <= 0) return t;

    for (int i = 1;i < n; ++i) {
      t += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    }

    return t;
  }
};

#endif /* !SOLUTION_H */
