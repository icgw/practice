/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <thread>
#include "solution.hpp"

void first() {
  std::cout << "first" ;
}

void second() {
  std::cout << "second";
}

void third() {
  std::cout << "third";
}

void run_example()
{
  Foo f;
  int arr[] = { 1, 3, 2 };

  std::thread threads[3];
  for (int i = 0; i < 3; ++i) {
    switch (arr[i]) {
      case 1:
        threads[i] = std::thread(&Foo::first, &f, first);
        break;
      case 2:
        threads[i] = std::thread(&Foo::second, &f, second);
        break;
      case 3:
        threads[i] = std::thread(&Foo::third, &f, third);
        break;
      default:
        break;
    }
  }

  for (auto &th : threads) th.join();

  std::cout << "\n";
}
