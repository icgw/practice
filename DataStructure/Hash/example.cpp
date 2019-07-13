/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hash_table.hpp"

constexpr int N         = 48;
constexpr int MAX_VALUE = 1000;

int main()
{
  srand(time(nullptr));

  hash_table table;

  // TEST: insert.
  for (int i = 0; i < N; ++i) {
    pRecord r = (pRecord) malloc(sizeof(Record));

    r->key  = rand() % MAX_VALUE;
    r->value = rand() % MAX_VALUE;

    if (table.search(r->key) != nullptr) {
      --i;
      continue;
    }

    std::cout << "Inserting: Key => " << r->key << ", Value =>" << r->value << "\n";
    table.insert(r);
  }

  // TEST: search & remove.
  pRecord tmp;
  for (int i = 0; i < MAX_VALUE; ++i) {
    if ((tmp = table.search(i)) != nullptr) {
      std::cout << "Deleting: Key => " << tmp->key << ", Value => " << tmp->value << "\n";
      table.remove(tmp->key);
    }
  }

  return 0;
}
