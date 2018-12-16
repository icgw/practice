#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = s.findDisappearedNumbers(nums);
    for (auto x : ans) std::cout << x << " ";
    std::cout << "\n";
}
