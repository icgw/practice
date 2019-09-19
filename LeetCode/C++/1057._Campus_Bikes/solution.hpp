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

#include <utility>
using std::pair;
using std::make_pair;

#include <cmath>
using std::abs;

class Solution {
public:
  vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    vector<vector<pair<int, int>>> bucket ( 2001 , vector<pair<int, int>>() );
    int wn = workers.size(), bn = bikes.size();

    for (int i = 0; i < wn; ++i) {
      for (int j = 0; j < bn; ++j) {
        vector<int> worker = workers[i], bike = bikes[j];
        int dist = abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
        bucket[dist].push_back(make_pair(i, j));
      }
    }

    vector<int> res ( wn, -1 );
    vector<int> bUsedBike ( bn, false );

    for (int i = 0; i < 2001; ++i) {
      int sz = bucket[i].size();
      for (int j = 0; j < sz; ++j) {
        pair<int, int> workerBike = bucket[i][j];
        if ( res[ workerBike.first ] == -1 && !bUsedBike[ workerBike.second ] ) {
          res[ workerBike.first ] = workerBike.second;
          bUsedBike[ workerBike.second ] = true;
        }
      }
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
