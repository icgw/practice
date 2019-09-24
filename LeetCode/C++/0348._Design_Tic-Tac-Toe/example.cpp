/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.hpp"

void run_example()
{
  TicTacToe* toe = new TicTacToe(3);

  std::cout << toe->move(0, 0, 1) << std::endl;
  std::cout << toe->move(0, 2, 2) << std::endl;
  std::cout << toe->move(2, 2, 1) << std::endl;
  std::cout << toe->move(1, 1, 2) << std::endl;
  std::cout << toe->move(2, 0, 1) << std::endl;
  std::cout << toe->move(1, 0, 2) << std::endl;
  std::cout << toe->move(2, 1, 1) << std::endl;

  delete toe;
}
