/*
 * mod.rs
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use crate::Solution;
use std::cmp;

impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        if nums1.len() > nums2.len() * 6 || nums1.len() * 6 < nums2.len() {
            return -1;
        }
        let sum1: i32 = nums1.iter().sum();
        let sum2: i32 = nums2.iter().sum();
        if sum1 > sum2 {
            return Solution::min_operations(nums2, nums1);
        }
        let mut sorted_nums1 = nums1.to_vec();
        sorted_nums1.sort();
        let mut sorted_nums2 = nums2.to_vec();
        sorted_nums2.sort();
        let mut diff = sum2 - sum1;
        let mut lo = 0 as i32;
        let mut hi = (nums2.len() - 1) as i32;
        let mut op = 0;
        while diff > 0 {
            let inc: i32 = if lo < nums1.len() as i32 { 6 - sorted_nums1[lo as usize] } else { 0 };
            let dec: i32 = if hi >= 0 { sorted_nums2[hi as usize] - 1 } else { 0 };
            let d = cmp::max(inc, dec);
            op += 1;
            if d >= diff {
                return op
            }
            diff -= d;
            if inc > dec {
                lo += 1;
            } else {
                hi -= 1;
            }
        }
        return op;
    }
}

#[cfg(test)]
mod tests {
    use crate::_1775_equal_sum_arrays_with_minimum_number_of_operations_::Solution;

    #[test]
    fn p1775_example_1() {
        let nums1 = vec![1, 2, 3, 4, 5, 6];
        let nums2 = vec![1, 1, 2, 2, 2, 2];
        assert_eq!(Solution::min_operations(nums1, nums2), 3);
    }

    #[test]
    fn p1775_example_2() {
        let nums1 = vec![1, 1, 1, 1, 1, 1, 1];
        let nums2 = vec![6];
        assert_eq!(Solution::min_operations(nums1, nums2), -1);
    }

    #[test]
    fn p1775_example_3() {
        let nums1 = vec![6, 6];
        let nums2 = vec![1];
        assert_eq!(Solution::min_operations(nums1, nums2), 3);
    }
}
