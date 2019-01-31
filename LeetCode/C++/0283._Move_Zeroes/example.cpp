#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (auto& n : nums) std::cout << n << " ";
    std::cout << std::endl;
}
