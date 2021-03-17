/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include "../data_structures.hpp"

class Solution {
private:
  void rightSideView(TreeNode* root, vector<int>& res, int depth) {
    if (!root) return;
    if (depth == res.size()) {
      res.push_back(root->val);
    }
    rightSideView(root->right, res, depth + 1);
    rightSideView(root->left, res, depth + 1);
  }
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res{};
    rightSideView(root, res, 0);
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

