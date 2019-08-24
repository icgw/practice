/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  int i, j;
  Node * left;
  Node * right;
  Node (int l, int r) :
    i(l), j(r), left(nullptr), right(nullptr) {}
};

void split4Me(vector<vector<int>>& nums, int split, vector<vector<int>>& left, vector<vector<int>>& right) {
  for (vector<int> i : nums) {
    if (i[0] < split) {
      left.push_back(i);
    }
    else if (i[0] > split) {
      right.push_back(i);
    }
  }
}

Node * helper(vector<vector<int>>& nums) {
  if (nums.empty()) return nullptr;
  vector<int> p = nums[0];
  int split = p[0];

  vector<vector<int>> left, right;
  split4Me(nums, split, left, right);

  Node * root = new Node (p[0], p[1]);
  root->left  = helper(left);
  root->right = helper(right);

  return root;
}

void transversePrint(Node * rt) {
  if (rt == nullptr) return;

  cout << "(" << rt->i << ", " << rt->j << ")" << endl;

  transversePrint(rt->left);
  transversePrint(rt->right);
}

int main() {
  vector<vector<int>> nums { { 1, 4 }, { 8, 5 }, { 3, 6 }, { 10, -1 }, { 4, 7 } };
  sort(nums.begin(), nums.end(), [](vector<int> &a, vector<int> &b) -> bool {
        return a[1] > b[1];
      });

  Node * treeNode = helper(nums);
  transversePrint(treeNode);

  return 0;
}
