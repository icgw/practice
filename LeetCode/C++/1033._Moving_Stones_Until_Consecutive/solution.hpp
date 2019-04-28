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
  vector<int> numMovesStones(int a, int b, int c) {
    if (a > b) {
      return numMovesStones(b, a, c);
    }

    if (c < a) {
      return numMovesStones(c, a, b);
    }

    if (c < b) {
      return numMovesStones(a, c, b);
    }

    int minimum_moves = ((a + 1 == b) ? 0 : 1) + ((b + 1 == c) ? 0 : 1);
    if (a + 2 == b) {
      minimum_moves = 1;
    }
    if (b + 2 == c) {
      minimum_moves = 1;
    }

    int maximum_moves = c - a - 2;
    return { minimum_moves, maximum_moves };
  }
};

#endif // ifndef _SOLUTION_HPP_
