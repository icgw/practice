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
private:
  bool isValidBST(const TreeNode* root, const TreeNode* min_node, const TreeNode* max_node) {
    if (root == nullptr) {
      return true;
    }
    if ((min_node != nullptr && root->val <= min_node->val) ||
        (max_node != nullptr && root->val >= max_node->val)) {
      return false;
    }
    return isValidBST(root->left, min_node, root) && isValidBST(root->right, root, max_node);
  }
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, nullptr, nullptr);
  }
};

#endif /* !_SOLUTION_H_ */

