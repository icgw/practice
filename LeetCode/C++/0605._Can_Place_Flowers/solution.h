/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sz = flowerbed.size();
    int prev = -2;
    int count = 0;
    for (int i = 0; i < sz; ++i) {
      if (flowerbed[i] == 1) {
        count += (i - prev - 2) / 2;
        prev = i;
      }
    }
    count += (sz - prev - 1) / 2;
    return count >= n;
  }
};

#endif /* !_SOLUTION_H_ */

