/*
 * example.cpp
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#include "solution.h"

void run_example()
{
  TreeNode* root = stringToTreeNode("[3, 1, 4, 3, null, 1, 5]");
  Solution sln;
  std::cout << sln.goodNodes(root) << "\n";
}

