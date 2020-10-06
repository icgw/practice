/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <unordered_map>
using std::unordered_map;

#include "../data_structures.hpp"

class Solution {
private:
  unordered_map<int, int> m;

  bool isEvenOddTree(TreeNode* root, int level) {
    if (!root) {
      return true;
    }

    if (level % 2 == 0 && (root->val % 2 == 0 || root->val <= m[level])) {
      return false;
    }

    if (level % 2 == 1 && (root->val % 2 == 1 || (m[level] > 0 && root->val >= m[level]))) {
      return false;
    }

    m[level] = root->val;

    return isEvenOddTree(root->left, level + 1) && isEvenOddTree(root->right, level + 1);
  }

public:
  bool isEvenOddTree(TreeNode* root) {
    return isEvenOddTree(root, 0);
  }
};

#endif /* !_SOLUTION_H_ */

