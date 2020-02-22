/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> freq;

    for (int a : arr) {
      int da = a + a;

      if (0 == a && freq.find(0) != freq.end())
        return true;

      if (freq.find(a) != freq.end())
        continue;

      if (freq.find(da) != freq.end())
        return true;

      int half = (a >> 1);

      if (half + half == a && freq.find(half) != freq.end())
        return true;

      freq.insert(a);
    }

    return false;
  }
};

#endif /* !SOLUTION_H */
