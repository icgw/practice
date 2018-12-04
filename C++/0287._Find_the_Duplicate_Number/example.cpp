#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> nums1 = {1, 3, 4, 2, 2};
    std::cout << s.findDuplicate(nums1) << std::endl;

    vector<int> nums2 = {3, 1, 3, 4, 2};
    std::cout << s.findDuplicate(nums2) << std::endl;
}
