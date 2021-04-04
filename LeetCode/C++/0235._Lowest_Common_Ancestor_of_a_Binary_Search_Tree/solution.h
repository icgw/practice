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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root && root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (root && root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};

#endif /* !_SOLUTION_H_ */

