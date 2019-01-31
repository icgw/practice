#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums { 2, 6, 4, 8, 10, 9, 15 };
    std::cout << s.findUnsortedSubarray(nums) << std::endl;
}
