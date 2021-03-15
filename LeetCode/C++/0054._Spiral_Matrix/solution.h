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

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int lowerBound = 0;
    int upperBound = matrix.size() - 1;
    int leftBound = 0;
    int rightBound = matrix[0].size() - 1;
    vector<int> res{};
    for (;;) {
      for (int i = leftBound; i <= rightBound; ++i) {
        res.emplace_back(matrix[lowerBound][i]);
      }
      ++lowerBound;
      if (lowerBound > upperBound) break;
      for (int i = lowerBound; i <= upperBound; ++i) {
        res.emplace_back(matrix[i][rightBound]);
      }
      --rightBound;
      if (rightBound < leftBound) break;
      for (int i = rightBound; i >= leftBound; --i) {
        res.emplace_back(matrix[upperBound][i]);
      }
      --upperBound;
      if (upperBound < lowerBound) break;
      for (int i = upperBound; i >= lowerBound; --i) {
        res.emplace_back(matrix[i][leftBound]);
      }
      ++leftBound;
      if (leftBound > rightBound) break;
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

