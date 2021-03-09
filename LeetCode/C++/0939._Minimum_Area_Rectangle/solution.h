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
#include <utility>
using std::pair;
#include <numeric>
using std::numeric_limits;
#include <algorithm>
using std::min;
#include <cmath>
using std::abs;

class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {
    set<pair<int, int>> setOfPoints;
    for (auto& p : points) {
      setOfPoints.insert({p[0], p[1]});
    }
    int n = points.size();
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        int x2 = points[j][0], y2 = points[j][1];
        if (x1 == x2 || y1 == y2) continue;
        if (setOfPoints.find({x1, y2}) != setOfPoints.end() &&
            setOfPoints.find({x2, y1}) != setOfPoints.end()) {
          ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
        }
      }
    }
    return ans == numeric_limits<int>::max() ? 0 : ans;
  }
};

#endif /* !_SOLUTION_H_ */

