#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums { 3, 1, 5, 8 };
    std::cout << s.maxCoins(nums) << std::endl;
}
