/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <algorithm>
using std::swap;
#include "../data_structures.hpp"

class Solution {
private:
  TreeNode* firstWrongNode = nullptr;
  TreeNode* secondWrongNode = nullptr;
  TreeNode* previousNode = nullptr;
  void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    if (firstWrongNode == nullptr && previousNode && previousNode->val >= root->val) {
      firstWrongNode = previousNode;
    }
    if (firstWrongNode != nullptr && previousNode && previousNode->val >= root->val) {
      secondWrongNode = root;
    }
    previousNode = root;
    traverse(root->right);
  }
public:
  void recoverTree(TreeNode* root) {
    traverse(root);
    swap(firstWrongNode->val, secondWrongNode->val);
  }
};

#endif /* !_SOLUTION_H_ */

