/*
 * avl_tree.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

struct Node {
  int value;
  int height;
  Node *left;
  Node *right;
};

class avl_tree {
public:
  // TODO: insert
  void insert(int v) {
    root = insert(root, v);
  }

  // TODO: remove

  // TODO: search

  // NOTE: get root node;
  Node * get_root() {
    return root;
  }

private:
  // NOTE: the default value.
  Node *root = nullptr;

  static int doBalance(Node * n) {
    return n == nullptr ? 0 : (height(n->left) - height(n->right));
  }

  static int max(int a, int b) {
    return a > b ? a : b;
  }

  static int height(Node *n) {
    return n == nullptr ? 0 : n->height;
  }

  static Node * rotate_left(Node *node);
  static Node * rotate_right(Node *node);

  Node * insert(Node * rt, int value);
};

inline
Node * avl_tree::rotate_left(Node *node)
{
  if (node == nullptr) return node;

  Node * r_node = node->right;
  Node * t_node = r_node->left;

  r_node->left = node;
  node->right  = t_node;

  // NOTE: update height.
  r_node->height = 1 + max(height(r_node->left), height(r_node->right));
  node->height   = 1 + max(height(node->left), height(node->right));

  return r_node;
}

inline
Node * avl_tree::rotate_right(Node *node)
{
  if (node == nullptr) return node;

  Node * l_node = node->left;
  Node * t_node = l_node->right;

  l_node->right = node;
  node->left    = t_node;

  // update.
  l_node->height = 1 + max(height(l_node->left), height(l_node->right));
  node->height   = 1 + max(height(node->left), height(node->right));

  return l_node;
}

inline
Node * avl_tree::insert(Node * rt, int value)
{
  if (rt == nullptr) {
    Node * n  = new Node;
    n->value  = value;
    n->height = 1;
    n->left   = n->right  = nullptr;
    return n;
  }

  int v = rt->value;
  if (value < v) {
    rt->left = insert(rt->left, value);
  }
  else if (value > v) {
    rt->right = insert(rt->right, value);
  }
  else {
    return rt;
  }

  // NOTE: update the height.
  rt->height = 1 + max(height(rt->left), height(rt->right));

  int balance = doBalance(rt);

  // Left Left.
  if (balance > 1 && value < rt->left->value) {
    return rotate_right(rt);
  }

  // Right Right.
  if (balance < -1 && value > rt->right->value) {
    return rotate_left(rt);
  }

  // Left Right.
  if (balance > 1 && value > rt->left->value) {
    rt->left = rotate_left(rt->left);
    return rotate_right(rt);
  }

  // Right Left.
  if (balance < -1 && value < rt->right->value) {
    rt->right = rotate_right(rt->right);
    return rotate_left(rt);
  }

  return rt;
}

#endif // ifndef _AVL_TREE_HPP_
