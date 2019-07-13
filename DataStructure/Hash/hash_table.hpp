/*
 * hash_table.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

struct Record {
  int key;
  int value;
};

typedef Record * pRecord;

class hash_table {
public:
  hash_table() {
    for (int i = 0; i < MAX_SIZE; ++i) {
      table[i] = nullptr;
    }
  }

  // TODO: release  the memory.
  ~hash_table() {}

  // NOTE: insert operation.
  void insert(pRecord r) {
    if (r == nullptr) return ;

    int i = hash(r->key);
    while (table[i] != nullptr) {
      i = (i + 1) % MAX_SIZE;
    }
    table[i] = r;
  }

  // NOTE: search
  pRecord search(int key) {
    int i = key;
    while (table[ hash(i) ] != nullptr && table[ hash(i) ]->key != key) {
      i = (i + 1) % MAX_SIZE;
    }
    return table[ hash(i) ];
  }

  // NOTE: remove
  void remove(int key) {
    int i = key;
    while (table[ hash(i) ] != nullptr && table[ hash(i) ]->key != key) {
      i = (i + 1) % MAX_SIZE;
    }

    table[ hash(i) ] = nullptr;

    for (i = (i + 1) % MAX_SIZE ; table[ hash(i) ] != nullptr; i = (i + 1) % MAX_SIZE) {
      insert(table[ hash(i) ]);
      table[ hash(i) ] = nullptr;
    }
  }

private:
  static constexpr int MAX_SIZE = 97;

  pRecord table[ MAX_SIZE ];

  // NOTE: hash function.
  int hash(int key) {
    return (key % MAX_SIZE);
  }
};

#endif // ifndef _HASH_TABLE_HPP_
