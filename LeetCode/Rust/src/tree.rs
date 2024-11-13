use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

pub struct TreeAlgorithm;

impl TreeAlgorithm {
    fn create_node(val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        return Some(Rc::new(RefCell::new(TreeNode::new(val))));
    }

    fn create_tree(
        val: i32,
        left: Option<Rc<RefCell<TreeNode>>>,
        right: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        return Some(Rc::new(RefCell::new(TreeNode { val, left, right })));
    }

    fn find_good_nodes(root: &Option<Rc<RefCell<TreeNode>>>, max_so_far: Option<i32>) -> i32 {
        if let Some(node) = root {
            let mut new_max = max_so_far.unwrap_or(node.borrow().val);
            let i: i32 = if node.borrow().val >= new_max {
                new_max = node.borrow().val;
                1
            } else {
                0
            };
            return i
                + TreeAlgorithm::find_good_nodes(&node.borrow().left, Some(new_max))
                + TreeAlgorithm::find_good_nodes(&node.borrow().right, Some(new_max));
        }
        return 0;
    }

    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        return TreeAlgorithm::find_good_nodes(&root, None);
    }
}

#[cfg(test)]
mod _leetcode1448_ {
    use crate::tree::TreeAlgorithm;

    #[test]
    fn case1() {
        // wait to improve the creating process.
        let n4 = TreeAlgorithm::create_node(3);
        let n6 = TreeAlgorithm::create_node(1);
        let n7 = TreeAlgorithm::create_node(5);
        let n3 = TreeAlgorithm::create_tree(4, n6, n7);
        let n2 = TreeAlgorithm::create_tree(1, n4, None);
        let n1 = TreeAlgorithm::create_tree(3, n2, n3);
        assert_eq!(TreeAlgorithm::good_nodes(n1), 4);
    }

    #[test]
    fn case2() {
        let n4 = TreeAlgorithm::create_node(4);
        let n5 = TreeAlgorithm::create_node(2);
        let n2 = TreeAlgorithm::create_tree(3, n4, n5);
        let n1 = TreeAlgorithm::create_tree(3, n2, None);
        assert_eq!(TreeAlgorithm::good_nodes(n1), 3);
    }

    #[test]
    fn case3() {
        let n1 = TreeAlgorithm::create_node(1);
        assert_eq!(TreeAlgorithm::good_nodes(n1), 1);
    }
}
