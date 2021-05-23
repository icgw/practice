/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */


#include <thread>
#include <iostream>
#include "solution.h"

void printFoo() {
  std::cout << "foo";
}

void printBar() {
  std::cout << "bar";
}

void run_example()
{
  FooBar fb1{5};
  std::thread t1{&FooBar::foo, &fb1, printFoo}, t2{&FooBar::bar, &fb1, printBar};
  t1.join();
  t2.join();
}
