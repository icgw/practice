/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <functional>
using std::function;
#include "../data_structures.hpp"

class Solution {
public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    int redLeft, redRight;
    redLeft = redRight = 0;
    function<int(TreeNode*)> dfs;
    dfs = [&](TreeNode* rt) -> auto {
      if (!rt) return 0;
      int l = dfs(rt->left);
      int r = dfs(rt->right);
      if (rt->val == x) {
        redLeft = l;
        redRight = r;
      }
      return l + r + 1;
    };
    dfs(root);
    int redParent = n - redLeft - redRight - 1;
    int half = n / 2;
    return redParent > half || redLeft > half || redRight > half;
  }
};

#endif /* !_SOLUTION_H_ */

