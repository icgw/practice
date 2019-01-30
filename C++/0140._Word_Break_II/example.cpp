#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    string s1 = "catsanddog";
    vector<string> wd1 { "cat", "cats", "and", "sand", "dog" };
    for (auto x : s.wordBreak(s1, wd1)) std::cout << x << std::endl;
    std::cout << "\n";

    string s2 = "pineapplepenapple";
    vector<string> wd2 { "apple", "pen", "applepen", "pine", "pineapple" };
    for (auto x : s.wordBreak(s2, wd2)) std::cout << x << std::endl;
    std::cout << "\n";

    string s3 = "catsandog";
    vector<string> wd3 = { "cats", "dog", "sand", "and", "cat" };
    for (auto x : s.wordBreak(s3, wd3)) std::cout << x << std::endl;
    std::cout << "\n";
}
