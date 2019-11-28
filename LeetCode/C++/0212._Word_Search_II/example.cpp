/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  vector<vector<char>> board {
    { 'o', 'a', 'a', 'n' },
    { 'e', 't', 'a', 'e' },
    { 'i', 'h', 'k', 'r' },
    { 'i', 'f', 'l', 'v' }
  };

  vector<string> words { "oath", "pea", "eat", "rain" };

  Solution sln;
  vector<string> res = sln.findWords(board, words);
  for (auto s : res) {
    std::cout << s << std::endl;
  }
}


