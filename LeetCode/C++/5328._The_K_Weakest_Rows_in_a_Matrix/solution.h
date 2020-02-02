/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <utility>
using std::pair;

#include <numeric>
using std::accumulate;

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    set<pair<int, int>> m;
    int nRows = mat.size();
    for (int i = 0; i < nRows; ++i) {
      int k = accumulate(begin(mat[i]), end(mat[i]), 0);
      m.insert({ k, i });
    }

    vector<int> res;
    for (auto it = begin(m); k > 0; --k, ++it) {
      res.push_back(it->second);
    }

    return res;
  }
};

#endif /* !SOLUTION_H */
