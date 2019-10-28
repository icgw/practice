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
  Solution sln;
  string text = "thestoryofleetcodeandme";
  vector<string> words { "story", "fleet", "leetcode" };
  for (auto &v : sln.indexPairs( text, words )) {
    for (auto x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
}
