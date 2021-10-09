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
using std::stol;
using std::to_string;
#include <cmath>
using std::log;
using std::pow;

class Solution {
private:
  long sum_of_geometric(long b, long k) {
    long s = 1, mul = 1;
    for (long i = 0; i < k; ++i) {
      mul *= b;
      s += mul;
    }
    return s;
  }

public:
  string smallestGoodBase(string n) {
    long val = stol(n);
    long max_m = log(val) / log(2);
    for (long m = max_m; m > 1; --m) {
      long b = pow(val, 1.0 / static_cast<double>(m));
      long s = sum_of_geometric(b, m);
      if (s == val) {
        return to_string(b);
      }
    }
    return to_string(val - 1);
  }
};

#endif /* !_SOLUTION_H_ */

