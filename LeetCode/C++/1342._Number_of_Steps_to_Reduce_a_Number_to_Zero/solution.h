/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
private:
  bool isOdd (int num) {
    return num & 1;
  }
public:
  int numberOfSteps (int num) {
    int cnt = 0;
    while (num) {
      if (isOdd(num)) {
        --num;
      } else {
        num >>= 1;
      }
      ++cnt;
    }
    return cnt;
  }
};

#endif /* !SOLUTION_H */
