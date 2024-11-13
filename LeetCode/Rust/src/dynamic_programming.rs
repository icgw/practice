pub struct DynamicProgrammingAlgorithm;

impl DynamicProgrammingAlgorithm {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount: usize = amount as usize;
        let mut dp: Vec<usize> = vec![amount + 1; amount + 1];
        dp[0] = 0;
        for i in 1..=amount {
            dp[i] = coins
                .iter()
                .filter(|it| i as i32 - *it >= 0)
                .map(|coin| i as i32 - coin)
                .fold(dp[i], |res, idx| std::cmp::min(res, dp[idx as usize] + 1));
        }
        if dp[amount] > amount {
            -1
        } else {
            dp[amount as usize] as i32
        }
    }
}

#[cfg(test)]
mod _leetcode322_ {
    use crate::dynamic_programming::DynamicProgrammingAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(
            DynamicProgrammingAlgorithm::coin_change(vec![1, 2, 5], 11),
            3
        );
    }

    #[test]
    fn case2() {
        assert_eq!(DynamicProgrammingAlgorithm::coin_change(vec![2], 3), -1);
    }

    #[test]
    fn case3() {
        assert_eq!(DynamicProgrammingAlgorithm::coin_change(vec![1], 0), 0);
    }

    #[test]
    fn case4() {
        assert_eq!(DynamicProgrammingAlgorithm::coin_change(vec![1], 1), 1);
    }

    #[test]
    fn case5() {
        assert_eq!(DynamicProgrammingAlgorithm::coin_change(vec![1], 2), 2);
    }
}
