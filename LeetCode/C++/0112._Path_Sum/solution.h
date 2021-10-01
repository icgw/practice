/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include "../data_structures.hpp"

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
  }
};

#endif /* !_SOLUTION_H_ */

