/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <stack>
using std::stack;

#include "../data_structures.hpp"

class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    pushAllLeft(root);
  }

  int next() {
    auto tmpNode = stk.top();
    stk.pop();
    pushAllLeft(tmpNode->right);
    return tmpNode->val;
  }

  bool hasNext() {
    return !stk.empty();
  }

private:
  stack<TreeNode*> stk{};

  void pushAllLeft(TreeNode* root) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
  }
};

#endif /* !_SOLUTION_H_ */

