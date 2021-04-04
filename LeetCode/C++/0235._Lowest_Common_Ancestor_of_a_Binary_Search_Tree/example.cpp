/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  Solution sln;
  TreeNode* root = stringToTreeNode("[6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]");
  TreeNode* p = root->left;
  TreeNode* q = root->left->right;
  TreeNode* lca = sln.lowestCommonAncestor(root, p, q);
  std::cout << lca->val << "\n";
}

