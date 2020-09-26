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
#include <string>
using std::string;
#include <algorithm>
using std::max;

class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> endPosition(26, 0);
    for (auto i = 0; i < S.size(); ++i) {
      endPosition[ S[i] - 'a' ] = i;
    }

    vector<int> res;
    for (int i = 0, idx = std::numeric_limits<int>::min(), last = -1; i < S.size(); ++i) {
      idx = max(idx, endPosition[ S[i] - 'a' ]);
      if (idx == i) {
        res.push_back(i - last);
        last = i;
      }
    }

    return res;
  }
};

#endif /* !_SOLUTION_H_ */

