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

class Solution {
private:
  int check(int x1, int i1, int n1, int x2, int i2, int n2, int x3, int i3, int n3) {
    int r1 = n1 - i1, r2 = n2 - i2, r3 = n3 - i3;
    if ((x1 < x2 || (x1 == x2 && r1 >= r2)) && (x1 < x3 || (x1 == x3 && r1 >= r3))) {
      return 1;
    }
    else if ((x2 < x1 || (x2 == x1 && r2 >= r1)) && (x2 < x3 || (x2 == x3 && r2 >= r3))) {
      return 2;
    }
    else if ((x3 < x1 || (x3 == x1 && r3 >= r1)) && (x3 < x2 || (x3 == x2 && r3 >= r2))) {
      return 3;
    }
    return 1;
  }

public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    vector<int> res;

    int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
    if (n1 == 0 || n2 == 0 || n3 == 0) return res;

    int i1, i2, i3;
    i1 = i2 = i3 = 0;

    while (i1 < n1 && i2 < n2 && i3 < n3) {
      int tmp = arr1[i1];
      if (tmp == arr2[i2] && tmp == arr3[i3]) {
        res.push_back(tmp);
      }

      switch (check(arr1[i1], i1, n1, arr2[i2], i2, n2, arr3[i3], i3, n3)) {
        case 1:
          ++i1;
          break;
        case 2:
          ++i2;
          break;
        case 3:
          ++i3;
          break;
      }
    }

    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
