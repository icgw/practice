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
  TreeNode* root = stringToTreeNode("[1, 2, 3, null, 5, null, 4]");
  vector<int> res = sln.rightSideView(root);
  for (int i : res) std::cout << i << "\n";
}

