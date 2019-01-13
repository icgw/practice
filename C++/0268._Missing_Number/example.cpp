#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 3, 0, 1 };
    std::cout << s.missingNumber(nums1) << std::endl;

    vector<int> nums2 { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    std::cout << s.missingNumber(nums2) << std::endl;
}
