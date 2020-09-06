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

class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();

    int res = ((n % 2 == 1) ? -mat[n / 2][n / 2] : 0);

    for (int i = 0; i < n; ++i) {
      res += (mat[i][i] + mat[i][n - i - 1]);
    }

    return res;
  }
};

#endif /* !_SOLUTION_H_ */

