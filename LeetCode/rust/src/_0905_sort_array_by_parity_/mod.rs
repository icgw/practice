/*
 * mod.rs
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


pub struct Solution;
impl Solution {
  pub fn sort_array_by_parity(a: Vec<i32>) -> Vec<i32> {
    let mut ret      = a.clone();
    let mut even_idx = 0;
    for i in 0..ret.len() {
      if ret[i] & 1 == 0 {
        ret.swap(i, even_idx);
        even_idx += 1;
      }
    }
    ret
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn it_works() {
    assert_eq!(Solution::sort_array_by_parity(vec![3, 1, 2, 4]), vec![2, 4, 3, 1]);
  }
}
