/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <queue>
using std::queue;
#include <utility>
using std::pair;
#include <algorithm>
using std::max;
#include "../data_structures.hpp"

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, size_t>> q;
    q.push({ root, 1 });
    size_t ans = 0;
    while (!q.empty()) {
      ans = max(ans, q.back().second - q.front().second + 1);
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        TreeNode* node = cur.first;
        if (node->left) {
          q.push({ node->left, 2 * cur.second });
        }
        if (node->right) {
          q.push({ node->right, 2 * cur.second + 1});
        }
        q.pop();
      }
    }
    return static_cast<int>(ans);
  }
};

#endif /* !_SOLUTION_H_ */

