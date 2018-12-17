#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums {1, 1, 1, 1, 1};
    std::cout << s.findTargetSumWays(nums, 3) << std::endl;
}
