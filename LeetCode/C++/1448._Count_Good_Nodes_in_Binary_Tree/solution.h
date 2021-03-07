/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <numeric>
using std::numeric_limits;
#include <algorithm>
using std::max;

#include "../data_structures.hpp"

class Solution {
private:
  int goodNodes(TreeNode* root, int value) {
    if (root == nullptr) {
      return 0;
    }
    int nextVal = max(root->val, value);
    return (root->val >= value ? 1 : 0) + goodNodes(root->left, nextVal) + goodNodes(root->right, nextVal);
  }
public:
  int goodNodes(TreeNode* root) {
    return goodNodes(root, numeric_limits<int>::min());
  }
};

#endif /* !_SOLUTION_H_ */

