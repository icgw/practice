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
  vector<int> preorder{3, 9, 20, 15, 7};
  vector<int> inorder{9, 3, 15, 20, 7};
  TreeNode* root = sln.buildTree(preorder, inorder);
  prettyPrintTree(root);
}

