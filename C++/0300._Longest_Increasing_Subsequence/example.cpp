#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << s.lengthOfLIS(nums) << std::endl;
}
