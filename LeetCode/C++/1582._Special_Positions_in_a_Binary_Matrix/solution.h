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
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    vector<int> rows(m, 0), cols(n, 0);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          ++rows[i], ++cols[j];
        }
      }
    }

    int res = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) ++res;
      }
    }

    return res;
  }
};

#endif /* !_SOLUTION_H_ */

