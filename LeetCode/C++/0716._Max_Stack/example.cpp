/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  MaxStack stk;
  stk.push(5);   // [5] the top of the stack and the maximum number is 5.
  stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
  stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
  stk.top();     // return 5, [5, 1, 5] the stack did not change.
  stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
  stk.top();     // return 1, [5, 1] the stack did not change.
  stk.peekMax(); // return 5, [5, 1] the stack did not change.
  stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
  stk.top();     // return 5, [5] the stack did not change.
}

