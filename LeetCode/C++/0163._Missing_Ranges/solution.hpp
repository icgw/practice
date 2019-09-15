/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    long ll = (long) lower;
    for (long n : nums) {
      n -= 1;
      if (ll == n) {
        res.push_back( to_string(ll) );
      }
      else if (ll < n) {
        res.push_back( to_string(ll) + "->" + to_string(n) );
      }

      ll = (long) n + 2;
    }

    if (ll == upper) {
      res.push_back( to_string(ll) );
    }
    else if (ll < upper) {
      res.push_back( to_string(ll) + "->" + to_string(upper) );
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
