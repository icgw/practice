#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.maxPathSum(stringToTreeNode("[1, 2, 3]")) << std::endl;
    std::cout << s.maxPathSum(stringToTreeNode("[-10, 9, 20, null, null, 15, 7]")) << std::endl;
}
