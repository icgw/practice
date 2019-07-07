/*
 * interval_tree.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _INTERVAL_TREE_HPP_
#define _INTERVAL_TREE_HPP_

struct Interval {
  int low, high;
};

struct ITNode {
  Interval *i;
  int max_value;
  ITNode *left, *right;
};

class IntervalTree {
public:
  // NOTE: Add an interval
  void insert(Interval i) {
    root = insert(root, i);
  }

  // TODO: Remove an interval

  // NOTE: Given an interval x, find if x overlaps with any of the existing intervals.
  Interval * overlapSearch(Interval i) {
    return overlapSearch(root, i);
  }

  IntervalTree() {}

  ~IntervalTree() {
    // TODO: delete ITNode from root.
  }

private:
  ITNode *root = nullptr;

  bool doOverlap(Interval i1, Interval i2);

  ITNode * insert(ITNode *root, Interval i);

  Interval * overlapSearch(ITNode *root, Interval i);
};

inline
bool IntervalTree::doOverlap(Interval i1, Interval i2) {
  return i1.low <= i2.high && i2.low <= i1.high;
}

inline
ITNode * IntervalTree::insert(ITNode *root, Interval i)
{
  if (root == nullptr) {
    root            = new ITNode;
    root->i         = new Interval(i);
    root->max_value = i.high;
    root->left      = root->right      = nullptr;
    return root;
  }

  int l = root->i->low;

  if (i.low < l) {
    root->left  = insert(root->left, i);
  } else {
    root->right = insert(root->right, i);
  }

  if (root->max_value < i.high) {
    root->max_value = i.high;
  }

  return root;
}

inline
Interval * IntervalTree::overlapSearch(ITNode *root, Interval i)
{
  if (root == nullptr) return nullptr;

  if (doOverlap(*(root->i), i)) return root->i;

  if (root->left != nullptr && i.low <= root->left->max_value)
    return overlapSearch(root->left, i);

  return overlapSearch(root->right, i);
}

#endif // ifndef _INTERVAL_TREE_HPP_
