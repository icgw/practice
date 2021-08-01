use std::rc::Rc;
use std::cell::RefCell;
pub struct Solution;
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
      right: None
    }
  }
}

pub fn create_node(val: i32) -> Option<Rc<RefCell<TreeNode>>> {
    return Some(Rc::new(RefCell::new(TreeNode::new(val))));
}

pub fn create_tree(val: i32, left: Option<Rc<RefCell<TreeNode>>>, right: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    return Some(Rc::new(RefCell::new(TreeNode {
        val,
        left,
        right,
    })));
}

pub mod _0001_two_sum_;
pub mod _0322_coin_change_;
pub mod _0709_to_lower_case_;
pub mod _0905_sort_array_by_parity_;
pub mod _1775_equal_sum_arrays_with_minimum_number_of_operations_;
pub mod _1647_minimum_deletions_to_make_character_frequencies_unique_;
pub mod _1448_count_good_nodes_in_binary_tree_;
pub mod _1337_the_k_weakest_rows_in_a_matrix_;
