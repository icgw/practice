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
#include <unordered_map>
using std::unordered_map;

class Solution {
public:

  int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> record{{0, 1}};
    int sum = 0, ans = 0;
    for (int a : A) {
      sum += a;
      int m = (sum % K + K) % K;
      ans += record[m];
      ++record[m];
    }
    return ans;
  }
  /*
  int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> record{{0, 1}};
    int sum = 0;
    for (int a : A) {
      sum += a;
      int m = (sum % K + K) % K;
      ++record[m];
    }
    int ans = 0;
    for (auto [_, cnt] : record) {
      ans += cnt * (cnt - 1) / 2;
    }
    return ans;
  }
  */
};

#endif /* !_SOLUTION_H_ */

