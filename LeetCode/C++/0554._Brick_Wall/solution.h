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
#include <map>
using std::map;
#include <algorithm>
using std::min;

class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    map<int, int> brickEdges;
    int height = wall.size();
    int minCross = height;
    for (auto& w : wall) {
      int width = 0;
      for (int i = 0; i < w.size() - 1; ++i) {
        width += w[i];
        minCross = min(minCross, height - (++brickEdges[width]));
      }
    }
    return minCross;
  }
};

#endif /* !_SOLUTION_H_ */

