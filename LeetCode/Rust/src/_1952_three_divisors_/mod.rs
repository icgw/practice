/*
 * mod.rs
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */


use crate::Solution;

impl Solution {
    fn is_prime(n: i32) -> bool {
        if n < 0 { return Solution::is_prime(-n); }
        if n % 2 == 0 { return false; }
        if n == 1 || n == 2 || n == 3 {
            return true;
        }
        let sq = (n as f32).sqrt() as i32;
        for i in (3..sq + 1).step_by(2) {
            if n % i == 0 {
                return false;
            }
        }
        return true;
    }
    pub fn is_three(n: i32) -> bool {
        if n == 4 { return true; }
        if n < 4 { return false; }
        let sq = (n as f32).sqrt() as i32;
        if sq * sq != n {
            return false;
        }
        return Solution::is_prime(sq)
    }
}

#[cfg(test)]
mod tests {
    use crate::_1952_three_divisors_::Solution;

    #[test]
    fn p1952_example_1() {
        assert_eq!(Solution::is_three(4), true);
    }

    #[test]
    fn p1952_example_2() {
        assert_eq!(Solution::is_three(1), false);
    }

    #[test]
    fn p1952_example_3() {
        assert_eq!(Solution::is_three(100), false);
    }
}
