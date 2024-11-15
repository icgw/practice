use std::cmp;
use std::i32;

pub struct CharactersAlgorithm;

impl CharactersAlgorithm {
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

    pub fn roman_to_int(s: String) -> i32 {
        let mut ans: i32 = 0;
        let mut last = '_';
        for c in s.chars() {
            match c {
                'I' => ans += 1,
                'V' => ans += 5,
                'X' => ans += 10,
                'L' => ans += 50,
                'C' => ans += 100,
                'D' => ans += 500,
                'M' => ans += 1000,
                _ => continue,
            }
            match last {
                'I' => if c == 'V' || c == 'X' { ans -= 2; },
                'X' => if c == 'L' || c == 'C' { ans -= 20; },
                'C' => if c == 'D' || c == 'M' { ans -= 200; },
                _ => ()
            }
            last = c;
        }
        ans
    }
}

#[cfg(test)]
mod _leetcode1647_ {
    use crate::characters::CharactersAlgorithm;

    #[test]
    fn case1() {
        let s = String::from("aab");
        assert_eq!(CharactersAlgorithm::min_deletions(s), 0);
    }

    #[test]
    fn case2() {
        let s = String::from("aaabbbcc");
        assert_eq!(CharactersAlgorithm::min_deletions(s), 2);
    }

    #[test]
    fn case3() {
        let s = String::from("ceabaacb");
        assert_eq!(CharactersAlgorithm::min_deletions(s), 2);
    }
}

#[cfg(test)]
mod _leetcode13_ {
    use crate::characters::CharactersAlgorithm;

    #[test]
    fn case1() {
        let s = String::from("MCMXCIV");
        assert_eq!(CharactersAlgorithm::roman_to_int(s), 1994);
    }
}