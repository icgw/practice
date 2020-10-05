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

#include <cmath>
using std::acos;
using std::atan2;

#include <algorithm>
using std::max;
using std::sort;

class Solution {
public:
  int visiblePoints(vector<vector<int>> points, int angle, vector<int>& location) {
    static double PI = acos(-1);
    vector<double> pointAngles;
    int duplicate = 0;
    for (const auto& p : points) {
      if (p[0] == location[0] && p[1] == location[1]) {
        ++duplicate;
      } else {
        double dy = p[1] - location[1];
        double dx = p[0] - location[0];
        double angle = atan2(dy, dx) * 180 / PI;
        pointAngles.emplace_back(angle);
      }
    }

    sort(begin(pointAngles), end(pointAngles));
    int n = pointAngles.size();
    for (int i = 0; i < n; ++i) {
      pointAngles.emplace_back(pointAngles[i] + 360);
    }

    int cnt = 0;
    for (int i = 0, start = 0; i < pointAngles.size(); ++i) {
      if (pointAngles[i] - pointAngles[start] > angle) {
        ++start;
      }
      cnt = max(cnt, i - start + 1);
    }

    return duplicate + cnt;
  }
};

#endif /* !_SOLUTION_H_ */

