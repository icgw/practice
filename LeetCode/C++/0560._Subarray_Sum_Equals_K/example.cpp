#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums { 1, 1, 1 };
    std::cout << s.subarraySum(nums, 2) << std::endl;
}
