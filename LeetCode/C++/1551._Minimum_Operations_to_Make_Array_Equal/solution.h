/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

class Solution {
public:
  int minOperations(int n) {
    int m = n / 2;
    return m * (n - m);
  }
};

#endif /* !_SOLUTION_H_ */

