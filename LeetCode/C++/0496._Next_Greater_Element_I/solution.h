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
#include <map>
using std::map;
#include <stack>
using std::stack;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> m;
    stack<int> stk;
    for (int i : nums2) {
      while (!stk.empty() && stk.top() < i) {
        m[stk.top()] = i;
        stk.pop();
      }
      stk.push(i);
    }
    vector<int> res;
    for (int i : nums1) {
      res.push_back((m.find(i) != m.end()) ? m[i] : -1);
    }
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

