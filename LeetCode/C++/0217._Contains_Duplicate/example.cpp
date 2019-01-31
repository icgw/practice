#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 1, 2, 3, 1 };
    std::cout << s.containsDuplicate(nums1) << std::endl;

    vector<int> nums2 { 1, 2, 3, 4 };
    std::cout << s.containsDuplicate(nums2) << std::endl;

    vector<int> nums3 { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    std::cout << s.containsDuplicate(nums3) << std::endl;
}
