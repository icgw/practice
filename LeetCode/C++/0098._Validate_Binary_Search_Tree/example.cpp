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
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  std::cout << sln.isValidBST(root) << "\n";
}
