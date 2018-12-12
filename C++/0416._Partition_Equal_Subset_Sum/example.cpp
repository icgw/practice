#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums1 {1, 5, 11, 5};
    std::cout << s.canPartition(nums1) << std::endl;

    vector<int> nums2 {1, 2, 3, 5};
    std::cout << s.canPartition(nums2) << std::endl;
}
