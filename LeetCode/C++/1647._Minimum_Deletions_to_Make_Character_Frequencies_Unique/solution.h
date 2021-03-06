/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <string>
using std::string;
#include <array>
using std::array;
#include <algorithm>
using std::sort;
#include <functional>
using std::greater;
#include <numeric>
using std::numeric_limits;
#include <algorithm>
using std::min;

class Solution {
public:
  int minDeletions(string s) {
    array<int, 26> freq{0};
    for (auto& ch : s) {
      ++freq[ch - 'a'];
    }
    sort(freq.begin(), freq.end(), greater<int>());
    int prev = numeric_limits<int>::max();
    int reservedCharacters = 0;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] == 0 || prev == 0) {
        break;
      }
      int f = min(freq[i], prev - 1);
      prev = f;
      reservedCharacters += prev;
    }
    return s.size() - reservedCharacters;
  }
};

#endif /* !_SOLUTION_H_ */

