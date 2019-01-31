#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums {2, 7, 11, 15};
    vector<int> ans = s.twoSum(nums, 9);
    for (auto &x : ans) std::cout << x << " ";
    std::cout << "\n";
}
