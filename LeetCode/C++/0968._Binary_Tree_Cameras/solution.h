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
  enum struct State { NOT_MONITORED, MONITORED_HAS_CAMERA, MONITORED_NO_CAMERA };
private:
  int _minimum_number_of_cameras;

  State determinate_state_by_postorder_traversal(TreeNode* root) {
    if (root == nullptr) {
      return State::MONITORED_NO_CAMERA;
    }
    auto left_child_state = determinate_state_by_postorder_traversal(root->left);
    auto right_child_state = determinate_state_by_postorder_traversal(root->right);
    if (left_child_state == State::NOT_MONITORED || right_child_state == State::NOT_MONITORED) {
      ++_minimum_number_of_cameras;
      return State::MONITORED_HAS_CAMERA;
    }
    if (left_child_state == State::MONITORED_NO_CAMERA && right_child_state == State::MONITORED_NO_CAMERA) {
      return State::NOT_MONITORED;
    }
    return State::MONITORED_NO_CAMERA;
  }

public:
  int minCameraCover(TreeNode* root) {
    _minimum_number_of_cameras = 0;
    if (determinate_state_by_postorder_traversal(root) == State::NOT_MONITORED) {
      ++_minimum_number_of_cameras;
    }
    return _minimum_number_of_cameras;
  }
};

#endif /* !_SOLUTION_H_ */

