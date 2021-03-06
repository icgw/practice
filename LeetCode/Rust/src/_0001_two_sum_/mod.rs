/*
 * mod.rs
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use std::collections::HashMap;
use crate::Solution;

impl Solution {
  pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut seen: HashMap<i32, i32> = HashMap::with_capacity(nums.len());
    for (i, num) in nums.iter().enumerate() {
      if seen.contains_key(num) {
        return vec![seen[num], i as i32];
      }
      seen.insert(target - num, i as i32);
    }
    vec![]
  }
}

#[cfg(test)]
mod tests {
  use crate::_0001_two_sum_::Solution;

  #[test]
  fn p0001_example_1() {
    assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
  }

  #[test]
  fn p0001_example_2() {
    assert_eq!(Solution::two_sum(vec![3, 2, 4], 6), vec![1, 2]);
  }

  #[test]
  fn p0001_example_3() {
    assert_eq!(Solution::two_sum(vec![3, 3], 6), vec![0, 1]);
  }
}
