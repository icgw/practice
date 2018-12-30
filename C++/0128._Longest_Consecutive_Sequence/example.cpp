#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums { 100, 4, 200, 1, 3, 2 };
    std::cout << s.longestConsecutive(nums) << std::endl;
}
