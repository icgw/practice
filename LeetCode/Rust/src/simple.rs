pub struct SimpleAlgorithm;

impl SimpleAlgorithm {
    pub fn to_lower_case(str: String) -> String {
        str.to_lowercase()
    }
}

#[cfg(test)]
mod _leetcode709_ {
    use crate::simple::SimpleAlgorithm;

    #[test]
    fn case1() {
        assert_eq!(
            SimpleAlgorithm::to_lower_case(String::from("LOVELY")),
            String::from("lovely")
        );
    }
}
