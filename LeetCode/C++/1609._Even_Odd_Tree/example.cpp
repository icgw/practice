/*
 * example.cpp
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#include <iostream>
#include "solution.h"

void run_example()
{
  Solution sln;

  TreeNode* root = stringToTreeNode("[1, 10, 4, 3, null, 7, 9, 12, 8, 6, null, null, 2]");
  std::cout << sln.isEvenOddTree(root) << "\n";
}

