/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <mutex>
using std::mutex;
#include <functional>
using std::function;

class Foo {
private:
  mutex m1, m2;

public:
  Foo() {
    m1.lock();
    m2.lock();
  }

  void first(function<void()> printFirst) {
    printFirst();
    m1.unlock();
  }

  void second(function<void()> printSecond) {
    m1.lock();
    printSecond();
    m1.unlock();
    m2.unlock();
  }

  void third(function<void()> printThird) {
    m2.lock();
    printThird();
    m2.unlock();
  }
};

#endif // ifndef _SOLUTION_HPP_
