#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.longestSubstring("aaabb", 3)  << std::endl;
    std::cout << s.longestSubstring("ababbc", 2) << std::endl;
}
