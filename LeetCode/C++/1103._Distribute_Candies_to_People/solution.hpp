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
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ret (num_people, 0);
    for (int i = 0, c = 1; candies > 0; ++c, ++i) {
      int add = ((candies >= c) ? c : candies);
      ret[i % num_people] += add;
      candies -= add;
    }
    return ret;
  }
};

#endif // ifndef _SOLUTION_HPP_
