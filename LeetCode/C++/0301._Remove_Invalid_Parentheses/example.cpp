#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;

    string s1 = "()())()";
    vector<string> ans1 = s.removeInvalidParentheses(s1);
    for (auto &x : ans1) std::cout << x << std::endl;
    std::cout << "\n";

    string s2 = "(a)())()";
    vector<string> ans2 = s.removeInvalidParentheses(s2);
    for (auto &x : ans2) std::cout << x << std::endl;
    std::cout << "\n";

    string s3 = ")(";
    vector<string> ans3 = s.removeInvalidParentheses(s3);
    for (auto &x : ans3) std::cout << x << std::endl;
    std::cout << "\n";
}
