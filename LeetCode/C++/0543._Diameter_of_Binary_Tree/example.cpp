#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    std::cout << s.diameterOfBinaryTree(stringToTreeNode("[1, 2, 3, 4, 5]"))
              << std::endl;
}
