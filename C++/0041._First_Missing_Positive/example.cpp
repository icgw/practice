#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 1, 2, 0 }, nums2 { 3, 4, -1, 1 }, nums3 { 7, 8, 9, 11, 12 };
    std::cout << s.firstMissingPositive(nums1) << std::endl;
    std::cout << s.firstMissingPositive(nums2) << std::endl;
    std::cout << s.firstMissingPositive(nums3) << std::endl;
}
