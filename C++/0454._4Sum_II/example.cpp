#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> A { 1, 2 }, B { -2, -1 }, C { -1, 2 }, D { 0, 2 };
    std::cout << s.fourSumCount(A, B, C, D) << std::endl;
}
