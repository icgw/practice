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
  TreeNode *tree = new TreeNode(3);
  tree->left = new TreeNode(5); tree->right = new TreeNode(1);
  tree->left->left = new TreeNode(6); tree->left->right = new TreeNode(2);
  tree->right->left = new TreeNode(0); tree->right->right = new TreeNode(8);
  tree->left->right->left = new TreeNode(7); tree->left->right->right = new TreeNode(4);
  TreeNode *p = tree->left, *q = tree->right;
  TreeNode *ans = sln.lowestCommonAncestor(tree, p, q);
  std::cout << ans->val << std::endl; // output: 3
}

