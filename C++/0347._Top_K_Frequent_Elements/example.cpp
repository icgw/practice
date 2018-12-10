#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums1 {1, 1, 1, 2, 2, 3};
    vector<int> ans1 = s.topKFrequent(nums1, 2);
    for (auto& x : ans1) std::cout << x << " ";
    std::cout << "\n";

    vector<int> nums2 {1};
    vector<int> ans2 = s.topKFrequent(nums2, 1);
    for (auto& x : ans2) std::cout << x << " ";
    std::cout << "\n";
}
