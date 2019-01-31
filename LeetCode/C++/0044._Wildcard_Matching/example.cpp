#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.isMatch("aa", "a") << std::endl;
    std::cout << s.isMatch("aa", "*") << std::endl;
    std::cout << s.isMatch("cb", "?a") << std::endl;
    std::cout << s.isMatch("adceb", "*a*b") << std::endl;
    std::cout << s.isMatch("acdcb", "a*c?b") << std::endl;
}
