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
#include <queue>
using std::queue;

class Solution {
public:
/*{{{ Brute Force (Time Limit Exceeded) */
  // vector<int> dailyTemperatures(vector<int>& T) {
  //   vector<int> res;
  //   int n = T.size();
  //   for (int i = 0; i < n; ++i) {
  //     int cnt = 1;
  //     for (int j = i + 1; j < n && T[j] <= T[i]; ++j, ++cnt);
  //     if (i + cnt >= n) cnt = 0;
  //     res.push_back(cnt);
  //   }
  //   return res;
  // }
/*}}}*/

  vector<int> dailyTemperatures(vector<int>& T) {
    int sz = T.size(), top_id = -1;
    vector<int> stk ( sz ), res ( sz, 0 );

    for (int i = 0; i < sz; ++i) {
      while (top_id != -1 && T[stk[top_id]] < T[i]) {
        res[stk[top_id]] = i - stk[top_id];
        --top_id;
      }
      stk[++top_id] = i;
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
