#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<int> heights { 2, 1, 5, 6, 2, 3 };
    std::cout << s.largestRectangleArea(heights) << std::endl;
}
