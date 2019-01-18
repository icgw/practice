#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 1, 2, 2, 1 }, nums2 { 2, 2 };
    vector<int> ans1 = s.intersect(nums1, nums2);
    for (auto x : ans1) std::cout << x << " ";
    std::cout << "\n";

    vector<int> nums21 { 4, 9, 5 }, nums22 { 9, 4, 9, 8, 4 };
    vector<int> ans2 = s.intersect(nums21, nums22);
    for (auto x : ans2) std::cout << x << " ";
    std::cout << "\n";
}
