/*
 * example.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "avl_tree.hpp"

void pre_order_print(Node * root) {
  if (root != nullptr) {
    std::cout << root->value << "\n";
    pre_order_print(root->left);
    pre_order_print(root->right);
  }
}

int main()
{
  avl_tree bbst;
  bbst.insert(10);
  bbst.insert(20);
  bbst.insert(30);
  bbst.insert(40);
  bbst.insert(50);
  bbst.insert(25);

  pre_order_print(bbst.get_root());

  return 0;
}
