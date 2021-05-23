/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <future>
using std::promise;
#include <functional>
using std::function;

class Foo {
private:
  promise<void> p1, p2;

public:
  Foo() {}

  void first(function<void()> printFirst) {
    printFirst();
    p1.set_value();
  }

  void second(function<void()> printSecond) {
    p1.get_future().get();
    printSecond();
    p2.set_value();
  }

  void third(function<void()> printThird) {
    p2.get_future().get();
    printThird();
  }
};

#endif // ifndef _SOLUTION_HPP_
