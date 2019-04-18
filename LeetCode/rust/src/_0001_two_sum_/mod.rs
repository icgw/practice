/*
 * mod.rs
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use std::collections::HashMap;

pub struct Solution;
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
  use super::*;

  #[test]
  fn it_works() {
    assert_eq!(Solution::two_sum(vec![ 2, 7, 11, 15 ], 9), vec![ 0, 1 ]);
  }
}
