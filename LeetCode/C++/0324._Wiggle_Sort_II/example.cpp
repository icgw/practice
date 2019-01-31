#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> nums1 { 1, 5, 1, 1, 6, 4 };
    s.wiggleSort(nums1);
    for (auto i : nums1) std::cout << i << " ";
    std::cout << "\n";

    vector<int> nums2 { 1, 3, 2, 2, 3, 1 };
    s.wiggleSort(nums2);
    for (auto i : nums2) std::cout << i << " ";
    std::cout << "\n";
}
