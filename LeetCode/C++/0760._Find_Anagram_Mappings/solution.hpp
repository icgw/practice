/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

class Solution {
public:
  vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    static unordered_map<int, int> m;
    for (int i = 0, bn = B.size(); i < bn; ++i) {
      m[B[i]] = i;
    }

    int an = A.size();
    vector<int> res ( an );
    for (int i = 0; i < an; ++i) {
      res[i] = m[A[i]];
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
