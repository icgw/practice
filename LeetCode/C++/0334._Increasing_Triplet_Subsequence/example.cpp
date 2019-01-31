#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 1, 2, 3, 4, 5 };
    std::cout << s.increasingTriplet(nums1) << std::endl;

    vector<int> nums2 { 5, 4, 3, 2, 1 };
    std::cout << s.increasingTriplet(nums2) << std::endl;
}
