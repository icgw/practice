/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include "trie.hpp"

int main()
{
  trie t;
  string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
  for (string s : keys) {
    t.insert(s);
  }

  t.search("the") ? std::cout << "Yes\n" : std::cout << "No\n";
  t.search("these") ? std::cout << "Yes\n" : std::cout << "No\n";

  return 0;
}
