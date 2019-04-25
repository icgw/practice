/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ret; 
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                ret.push_back({ i, j });
            }
        }
        sort(ret.begin(), ret.end(), [=](vector<int> &a, vector<int> &b) ->
                                     bool {
                                       int da = abs(a[0] - r0) + abs(a[1] - c0);
                                       int db = abs(b[0] - r0) + abs(b[1] - c0);
                                       return da < db;
                                     });
        return ret;
    }
};
