#include <iostream>
#include "solution.hpp"

void run_example() {
    vector<int> nums { 1, 2, 3 };
    Solution s(nums);
    for (auto i : s.shuffle()) std::cout << i << " ";
    std::cout << "\n";

    for (auto i : s.reset()) std::cout << i << " ";
    std::cout << "\n";

    for (auto i : s.shuffle()) std::cout << i << " ";
    std::cout << "\n";
}
