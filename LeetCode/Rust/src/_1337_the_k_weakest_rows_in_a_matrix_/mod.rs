/*
 * mod.rs
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */
use crate::Solution;

impl Solution {
    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut ranking: Vec<(i32, i32)> = mat
            .iter()
            .enumerate()
            .map(|(idx, row_vals)| (row_vals.iter().sum(), idx as i32))
            .collect();
        ranking.sort();
        ranking.iter().take(k as usize).map(|x| x.1).collect()
    }
}

#[cfg(test)]
mod tests {
    use crate::_1337_the_k_weakest_rows_in_a_matrix_::Solution;

    #[test]
    fn p1337_example_1() {
        let mat: Vec<Vec<i32>> = vec![
          vec![1, 1, 0, 0, 0],
          vec![1, 1, 1, 1, 0],
          vec![1, 0, 0, 0, 0],
          vec![1, 1, 0, 0, 0],
          vec![1, 1, 1, 1, 1]
        ];
        let k: i32 = 3;
        assert_eq!(Solution::k_weakest_rows(mat, k), vec![2, 0, 3]);
    }
}
