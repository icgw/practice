#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums { 1, 3, -1, -3, 5, 3, 6, 7 };
    vector<int> ans = s.maxSlidingWindow(nums, 3);
    for (auto n : ans) std::cout << n << " ";
    std::cout << "\n";
}
