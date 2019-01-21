#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    string s1("leetcode"), s2("loveleetcode");

    std::cout << "s = \"" << s1 << "\"\n";
    std::cout << "return " << s.firstUniqChar(s1) << "." << std::endl;
    std::cout << "\n";
    std::cout << "s = \"" << s2 << "\"\n";
    std::cout << "return " << s.firstUniqChar(s2) << "." << std::endl;
}
