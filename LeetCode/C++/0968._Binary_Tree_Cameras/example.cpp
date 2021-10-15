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
  TreeNode* root = new TreeNode(0);
  root->left = new TreeNode(0);
  root->right = nullptr;
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(0);
  std::cout << sln.minCameraCover(root) << "\n";
}

