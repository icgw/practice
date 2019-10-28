/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
public:
  vector<vector<int>> indexPairs(string text, vector<string>& words) {
    vector<vector<int>> res;
    for(auto w : words) {
      for (int p = text.find(w); p != string::npos; p = text.find(w, p + 1)) {
        res.push_back( { p, p + static_cast<int>(w.size()) - 1 } );
      }
    }
    sort(begin(res), end(res));
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
