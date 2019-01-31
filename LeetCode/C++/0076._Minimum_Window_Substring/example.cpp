#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    string S = "ADOBECODEBANC", T = "ABC";
    std::cout << s.minWindow(S, T) << std::endl;
}
