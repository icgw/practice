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
  TreeNode* root = stringToTreeNode("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]");
  int n = 11;
  int x = 3;
  std::cout << sln.btreeGameWinningMove(root, n, x) << "\n";
}

