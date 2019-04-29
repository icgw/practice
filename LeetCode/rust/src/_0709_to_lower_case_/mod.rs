/*
 * mod.rs
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

pub struct Solution;
impl Solution {
  pub fn to_lower_case(str: String) -> String {
    str.to_lowercase()
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn it_works() {
    assert_eq!(Solution::to_lower_case(String::from("LOVELY")), String::from("lovely"));
  }
}
