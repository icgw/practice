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
  TreeNode* root = stringToTreeNode("[1, 3, null, null, 2]");
  prettyPrintTree(root);
  sln.recoverTree(root);
  prettyPrintTree(root);
}

