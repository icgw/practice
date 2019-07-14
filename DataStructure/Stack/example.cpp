/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "stack.hpp"

int main()
{
  stack stk;
  stk.push(1);
  stk.push(2);

  std::cout << "After push 1, 2, then stk.top() => " << stk.top() << "\n";

  stk.pop();
  std::cout << "After push 1, 2, pop, then stk.top() => " << stk.top() << "\n";
  stk.pop();

  stk.push(3);
  std::cout << "After push 1, 2, pop, pop, push 3, then stk.top() => ";
  std::cout << stk.top() << "\n";

  return 0;
}
