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
  vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) {
      return {};
    }
    vector<int> tri(rowIndex + 1, 0);
    tri[0] = 1;
    for (int i = 0; i < rowIndex; ++i) {
      for (int k = i + 1; k > 0; --k) {
        tri[k] += tri[k - 1];
      }
    }
    return tri;
  }
};

#endif /* !_SOLUTION_H_ */

