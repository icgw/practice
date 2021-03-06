/*
 * mod.rs
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use crate::Solution;

impl Solution {
  pub fn to_lower_case(str: String) -> String {
    str.to_lowercase()
  }
}

#[cfg(test)]
mod tests {
  use crate::_0709_to_lower_case_::Solution;

  #[test]
  fn p0709() {
    assert_eq!(Solution::to_lower_case(String::from("LOVELY")), String::from("lovely"));
  }
}
