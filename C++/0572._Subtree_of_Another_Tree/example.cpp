#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    std::cout << s.isSubtree(stringToTreeNode("[3, 4, 5, 1, 2]"),
                             stringToTreeNode("[4, 1, 2]"))
              << std::endl;

    std::cout << s.isSubtree(stringToTreeNode("[3, 4, 5, 1, 2, null, null, null, null, 0]"),
                             stringToTreeNode("[4, 1, 2]"))
              << std::endl;
}
