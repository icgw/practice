/*
 * solution.h
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <utility>
using std::pair;
using std::make_pair;

class Solution {
private:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size(), res = 0;
    for (int i = 0; i < n; ++i) {
      int dx, dy, overlap = 0, max_cnt = 0;
      map<pair<int, int>, int> cnt;
      for (int j = 0; j < n; ++j) {
        dx = points[i][0] - points[j][0];
        dy = points[i][1] - points[j][1];

        if (dx == 0 && dy == 0) {
          ++overlap;
          continue;
        }

        int g = gcd(dx, dy);
        dx /= g, dy /= g;

        pair<int, int> dxdy = make_pair(dx, dy);
        if (cnt.find(dxdy) == cnt.end()) {
          cnt[dxdy] = 0;
        }
        ++cnt[dxdy];

        if (cnt[dxdy] > max_cnt) max_cnt = cnt[dxdy];
      }
      max_cnt += overlap;
      if (max_cnt > res) res = max_cnt;
    }
    return res;
  }
};

#endif /* !SOLUTION_H */
