/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
#include <string>
using std::vector;
using std::string;

#include <map>
using std::map;

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map<string, map<string, double>> quot;
    int n = equations.size();

    // NOTE: initial
    for (int i = 0; i < n; ++i) {
      string numerator   = equations[i][0];
      string denominator = equations[i][1];

      quot[numerator][numerator] = quot[denominator][denominator] = 1.0;

      quot[numerator][denominator] = values[i];
      quot[denominator][numerator] = 1.0 / values[i];
    }

    // auto := map<string, map<string, double>>::const_iterator
    // NOTE: outer loop is key
    for (auto it = quot.cbegin(); it != quot.cend(); ++it) {
      string key = it->first;
      auto value = it->second;
      for (auto i = value.cbegin(); i != value.cend(); ++i) {
        for (auto j = value.cbegin(); j != value.cend(); ++j) {
          string ki = i->first, kj = j->first;
          quot[ki][kj] = quot[ki][key] * quot[key][kj];
        }
      }
    }

    vector<double> res;
    for (vector<string> q : queries) {
      string q1 = q[0], q2 = q[1];
      if (quot.find(q1) == quot.end()) {
        res.push_back(-1.0);
      }
      else if (quot[q1].find(q2) == quot[q1].end()) {
        res.push_back(-1.0);
      }
      else {
        res.push_back(quot[q1][q2]);
      }
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
