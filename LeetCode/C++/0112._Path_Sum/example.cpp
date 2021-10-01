/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4); root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->right->left = new TreeNode(13); root->right->right = new TreeNode(4);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->right->right = new TreeNode(1);
  std::cout << sln.hasPathSum(root, 22) << "\n";
}
