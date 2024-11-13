use std::cmp;
use std::collections::HashMap;

pub struct ArrayAlgorithm;

impl ArrayAlgorithm {
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

    pub fn sort_array_by_parity(a: Vec<i32>) -> Vec<i32> {
        let mut ret = a.clone();
        let mut even_idx = 0;
        for i in 0..ret.len() {
            if ret[i] & 1 == 0 {
                ret.swap(i, even_idx);
                even_idx += 1;
            }
        }
        ret
    }

    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut ranking: Vec<(i32, i32)> = mat
            .iter()
            .enumerate()
            .map(|(idx, row_vals)| (row_vals.iter().sum(), idx as i32))
            .collect();
        ranking.sort();
        ranking.iter().take(k as usize).map(|x| x.1).collect()
    }

    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        if nums1.len() > nums2.len() * 6 || nums1.len() * 6 < nums2.len() {
            return -1;
        }
        let sum1: i32 = nums1.iter().sum();
        let sum2: i32 = nums2.iter().sum();
        if sum1 > sum2 {
            return ArrayAlgorithm::min_operations(nums2, nums1);
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
            let inc: i32 = if lo < nums1.len() as i32 {
                6 - sorted_nums1[lo as usize]
            } else {
                0
            };
            let dec: i32 = if hi >= 0 {
                sorted_nums2[hi as usize] - 1
            } else {
                0
            };
            let d = cmp::max(inc, dec);
            op += 1;
            if d >= diff {
                return op;
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
mod _leetcode1_ {
    use crate::array::ArrayAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(ArrayAlgorithm::two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
    }

    #[test]
    fn case2() {
        assert_eq!(ArrayAlgorithm::two_sum(vec![3, 2, 4], 6), vec![1, 2]);
    }

    #[test]
    fn case3() {
        assert_eq!(ArrayAlgorithm::two_sum(vec![3, 3], 6), vec![0, 1]);
    }
}

#[cfg(test)]
mod _leetcode905_ {
    use crate::array::ArrayAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(
            ArrayAlgorithm::sort_array_by_parity(vec![3, 1, 2, 4]),
            vec![2, 4, 3, 1]
        );
    }
}

#[cfg(test)]
mod _leetcode1337_ {
    use crate::array::ArrayAlgorithm;

    #[test]
    fn case1() {
        let mat: Vec<Vec<i32>> = vec![
            vec![1, 1, 0, 0, 0],
            vec![1, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0],
            vec![1, 1, 0, 0, 0],
            vec![1, 1, 1, 1, 1],
        ];
        let k: i32 = 3;
        assert_eq!(ArrayAlgorithm::k_weakest_rows(mat, k), vec![2, 0, 3]);
    }
}

#[cfg(test)]
mod _leetcode1775_ {
    use crate::array::ArrayAlgorithm;

    #[test]
    fn case1() {
        let nums1 = vec![1, 2, 3, 4, 5, 6];
        let nums2 = vec![1, 1, 2, 2, 2, 2];
        assert_eq!(ArrayAlgorithm::min_operations(nums1, nums2), 3);
    }

    #[test]
    fn case2() {
        let nums1 = vec![1, 1, 1, 1, 1, 1, 1];
        let nums2 = vec![6];
        assert_eq!(ArrayAlgorithm::min_operations(nums1, nums2), -1);
    }

    #[test]
    fn case3() {
        let nums1 = vec![6, 6];
        let nums2 = vec![1];
        assert_eq!(ArrayAlgorithm::min_operations(nums1, nums2), 3);
    }
}
