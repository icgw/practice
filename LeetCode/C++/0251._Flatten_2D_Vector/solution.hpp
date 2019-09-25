/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class Vector2D {
private:
  vector<vector<int>>::iterator OutIte;
  vector<vector<int>>::iterator OutEnd;
  vector<int>::iterator inIte;
  vector<int>::iterator inEnd;

public:
    Vector2D(vector<vector<int>>& v) {
      OutIte = v.begin();
      OutEnd = v.end();
      if (OutIte == OutEnd) return;
      inIte = OutIte->begin();
      inEnd = OutIte->end();
    }

    int next() {
      hasNext();
      return *inIte++;
    }

    bool hasNext() {
      while (OutIte != OutEnd && inIte == inEnd) {
        ++OutIte;
        if (OutIte == OutEnd) return false;
        inIte = OutIte->begin();
        inEnd = OutIte->end();
      }
      return OutIte != OutEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#endif // ifndef _SOLUTION_HPP_
