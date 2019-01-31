#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    std::cout << s.rob(stringToTreeNode("[3, 2, 3, null, 3, null, 1]")) << std::endl;
    std::cout << s.rob(stringToTreeNode("[3, 4, 5, 1, 3, null, 1]")) << std::endl;
}
