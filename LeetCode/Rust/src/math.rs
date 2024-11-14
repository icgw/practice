pub struct MathAlgorithm;

impl MathAlgorithm {
    fn is_prime(n: i32) -> bool {
        if n < 0 {
            return MathAlgorithm::is_prime(-n);
        }
        if n % 2 == 0 {
            return false;
        }
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

    fn is_three(n: i32) -> bool {
        if n == 4 {
            return true;
        }
        if n < 4 {
            return false;
        }
        let sq = (n as f32).sqrt() as i32;
        if sq * sq != n {
            return false;
        }
        return MathAlgorithm::is_prime(sq);
    }

    fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0) {
            return false;
        }
        let mut x = x;
        let mut y = 0;
        while x > y {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        x == y || y / 10 == x
    }
}

#[cfg(test)]
mod _leetcode1952_ {
    use crate::math::MathAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(MathAlgorithm::is_three(4), true);
    }

    #[test]
    fn case2() {
        assert_eq!(MathAlgorithm::is_three(1), false);
    }

    #[test]
    fn case3() {
        assert_eq!(MathAlgorithm::is_three(100), false);
    }
}

#[cfg(test)]
mod _leetcode9_ {
    use crate::math::MathAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(MathAlgorithm::is_palindrome(121), true);
    }
}
