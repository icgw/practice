/*
 * mod.rs
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use crate::Solution;
use crate::TreeNode;
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    fn find_good_nodes(root: &Option<Rc<RefCell<TreeNode>>>, max_so_far: Option<i32>) -> i32 {
        if let Some(node) = root {
            let mut new_max = max_so_far.unwrap_or(node.borrow().val);
            let i: i32 = if node.borrow().val >= new_max {
                new_max = node.borrow().val;
                1
            } else {
                0
            };
            return i + Solution::find_good_nodes(&node.borrow().left, Some(new_max)) + Solution::find_good_nodes(&node.borrow().right, Some(new_max));
        }
        return 0;
    }

    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return Solution::find_good_nodes(&root, None);
    }
}

#[cfg(test)]
mod tests {
    use crate::_1448_count_good_nodes_in_binary_tree_::Solution;

    #[test]
    fn p1448_example_1() { // wait to improve the creating process.
        let n4 = crate::create_node(3);
        let n6 = crate::create_node(1);
        let n7 = crate::create_node(5);
        let n3 = crate::create_tree(4, n6, n7);
        let n2 = crate::create_tree(1, n4, None);
        let n1 = crate::create_tree(3, n2, n3);
        assert_eq!(Solution::good_nodes(n1), 4);
    }

    #[test]
    fn p1448_example_2() {
        let n4 = crate::create_node(4);
        let n5 = crate::create_node(2);
        let n2 = crate::create_tree(3, n4, n5);
        let n1 = crate::create_tree(3, n2, None);
        assert_eq!(Solution::good_nodes(n1), 3);
    }

    #[test]
    fn p1448_example_3() {
        let n1 = crate::create_node(1);
        assert_eq!(Solution::good_nodes(n1), 1);
    }
}
