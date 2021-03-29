/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <cstdint>

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    n = ((n & 0x0000ffff) << 16) | ((n & 0xffff0000) >> 16);
    n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8);
    n = ((n & 0x0f0f0f0f) << 4 | (n & 0xf0f0f0f0) >> 4);
    n = ((n & 0x33333333) << 2 | (n & 0xcccccccc) >> 2);
    return (n & 0x55555555) << 1 | (n & 0xaaaaaaaa) >> 1;
  }
};

#endif /* !_SOLUTION_H_ */

