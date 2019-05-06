/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return ( points[1][1] * (points[2][0] - points[0][0])
               + points[2][1] * (points[0][0] - points[1][0])
               + points[0][1] * (points[1][0] - points[2][0]) ) != 0;
    }
};

#endif // ifndef _SOLUTION_HPP_
