/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
  bool isRobotBounded(string instructions) {
    static vector<vector<int>> dirs { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    vector<int> pos = { 0, 0 };
    int k = 0;
    for (char ins : instructions) {
      if ('G' == ins) {
        pos[0] += dirs[k][0];
        pos[1] += dirs[k][1];
      }
      else if ('L' == ins) {
        k = (k + 3) % 4;
      }
      else if ('R' == ins) {
        k = (k + 1) % 4;
      }
    }
    return (pos[0] == 0 && pos[1] == 0) || k > 0;
  }
};

#endif // ifndef _SOLUTION_HPP_
