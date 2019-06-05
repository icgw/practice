/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

// #include <unordered_set>
// #include <vector>
#include <string>
#include <algorithm>

// using std::unordered_set;
// using std::vector;
using std::string;
using std::swap;

class Solution {
public:
  bool isVowels(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }

  string reverseVowels(string s) {
    int lo = 0, hi = s.size() - 1;
    while (lo < hi) {
      if (isVowels(s[lo]) && isVowels(s[hi])) {
        swap(s[lo++], s[hi--]);
      }
      else if (!isVowels(s[lo])) {
        ++lo;
      }
      else if (!isVowels(s[hi])) {
        --hi;
      }
    }
    return s;
  }

  // string reverseVowels(string s) {
  //   unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
  //   vector<int> position;
  //   int sz = s.size();
  //   for (int i = 0; i < sz; ++i) {
  //     if (vowels.find(tolower(s[i])) != vowels.end()) {
  //       position.push_back(i);
  //     }
  //   }
  //   int n = position.size() / 2;
  //   for (int i = 0; i < n; ++i) {
  //     swap(s[position[i]], s[position[position.size() - 1 - i]]);
  //   }
  //   return s;
  // }
};

#endif // ifndef _SOLUTION_HPP_
