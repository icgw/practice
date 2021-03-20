/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <unordered_map>
using std::unordered_map;
#include "../data_structures.hpp"

class Solution {
  TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight,
                      vector<int>& inorder, int inLeft, int inRight,
                      unordered_map<int, int>& m) {
    if (preLeft > preRight || inLeft > inRight) return nullptr;
    int rootVal = preorder[preLeft];
    TreeNode* root = new TreeNode(rootVal);
    int pIndex = m[rootVal];
    root->left = buildTree(preorder, preLeft + 1, preLeft + pIndex - inLeft,
                           inorder, inLeft, pIndex - 1,
                           m);
    root->right = buildTree(preorder, preLeft + pIndex - inLeft + 1, preRight,
                            inorder, pIndex + 1, inRight,
                            m);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // preorder: [3] [9] [20, 15, 7]
    //        1. preLeft preLeft + 1 preLeft + pIndex - inLeft is the left tree.
    //        2. preLeft + pIndex - inLeft + 1, preRight is the right tree.
    // inorder:  [9] [3] [15, 20, 7]
    //       00. pIndex = m[preorder[preLeft]];
    //        0. pIndex - inLeft equals the length of left tree.
    //        1. inLeft pIndex - 1 is the left tree.
    //        2. pIndex + 1, inRight is the right tree.
    // init a map `m` for inorder: map value to index for finding the index of the root of tree.
    unordered_map<int, int> m{};
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      m[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1,
                     m);
  }
};

#endif /* !_SOLUTION_H_ */

