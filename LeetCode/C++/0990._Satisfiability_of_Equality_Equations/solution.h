/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <numeric>
using std::iota;

class UnionFind {
private:
  vector<int> parent{};
  int size;
public:
  UnionFind(int n) : parent(n, 0), size(n) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int index) {
    if (index < 0 || index >= size) return index;
    if (parent[index] == index) {
      return index;
    }
    parent[index] = find(parent[index]);
    return parent[index];
  }

  void unite(int i1, int i2) {
    int p1 = find(i1);
    int p2 = find(i2);
    parent[p1] = p2;
  }
};

class Solution {
public:
  bool equationsPossible(vector<string>& equations) {
    UnionFind u(26);
    for (const auto& eq : equations) {
      if (eq[1] == '=') {
        u.unite(eq[0] - 'a', eq[3] - 'a');
      }
    }
    for (const auto& eq : equations) {
      if (eq[1] == '!') {
        int p1 = u.find(eq[0] - 'a');
        int p2 = u.find(eq[3] - 'a');
        if (p1 == p2) {
          return false;
        }
      }
    }
    return true;
  }
};

#endif /* !_SOLUTION_H_ */

