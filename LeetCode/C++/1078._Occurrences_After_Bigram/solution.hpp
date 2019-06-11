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
#include <string>
using std::string;
#include <sstream>
using std::istringstream;


class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> res;
    string pprev, prev, tmp;
    istringstream is(text);

    while (is >> tmp) {
      if (first == pprev && second == prev) {
        res.push_back(tmp);
      }
      pprev = prev;
      prev  = tmp;
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
