/*
 * mod.rs
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use crate::Solution;
use std::i32;
use std::cmp;

impl Solution {
    pub fn min_deletions(s: String) -> i32 {
        let mut frequences = vec![0; 26];
        for ch in s.chars() {
            frequences[ch as usize - 'a' as usize] += 1;
        }
        frequences.sort_by(|left, right| right.cmp(left)); // sort by descending order.
        let mut prev = i32::MAX;
        let mut reserved_characters: i32 = 0;
        for freq in frequences {
            if freq == 0 || prev == 0 {
                break;
            }
            let f = cmp::min(freq, prev - 1);
            prev = f;
            reserved_characters += prev;
        }
        return s.len() as i32 - reserved_characters;
    }
}

#[cfg(test)]
mod tests {
    use crate::_1647_minimum_deletions_to_make_character_frequencies_unique_::Solution;

    #[test]
    fn p1647_example_1() {
        let s = String::from("aab");
        assert_eq!(Solution::min_deletions(s), 0);
    }

    #[test]
    fn p1647_example_2() {
        let s = String::from("aaabbbcc");
        assert_eq!(Solution::min_deletions(s), 2);
    }

    #[test]
    fn p1647_example_3() {
        let s = String::from("ceabaacb");
        assert_eq!(Solution::min_deletions(s), 2);
    }
}
