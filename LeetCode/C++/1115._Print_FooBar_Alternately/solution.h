/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <mutex>
using std::mutex;
#include <functional>
using std::function;

class FooBar {
private:
  int n;
  mutex m1, m2;
public:
  FooBar(int n) {
    this->n = n;
    m2.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; ++i) {
      m1.lock();
      printFoo();
      m2.unlock();
    }
    return;
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; ++i) {
      m2.lock();
      printBar();
      m1.unlock();
    }
  }
};

#endif /* !_SOLUTION_H_ */

