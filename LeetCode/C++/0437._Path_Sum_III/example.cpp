#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    std::cout << s.pathSum(
            stringToTreeNode("[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]"),
            8) << std::endl;
}
