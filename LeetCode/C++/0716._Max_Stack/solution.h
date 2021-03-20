/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <stack>
using std::stack;

class MaxStack {
  stack<int> stk, maxStk;
public:
  MaxStack() {}

  void push(int x) {
    if (maxStk.empty() || x >= maxStk.top()) {
      maxStk.push(x);
    } else {
      maxStk.push(maxStk.top());
    }
    stk.push(x);
  }

  int pop() {
    int r = stk.top();
    maxStk.pop();
    stk.pop();
    return r;
  }

  int top() {
    return stk.top();
  }

  int peekMax() {
    return maxStk.top();
  }

  int popMax() {
    int m = maxStk.top();
    stack<int> buffer{};
    while (!stk.empty() && stk.top() != m) {
      buffer.push(stk.top());
      this->pop();
    }
    this->pop();
    while (!buffer.empty()) {
      this->push(buffer.top());
      buffer.pop();
    }
    return m;
  }
};

#endif /* !_SOLUTION_H_ */

