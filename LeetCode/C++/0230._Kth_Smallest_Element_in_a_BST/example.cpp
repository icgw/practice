#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.kthSmallest(stringToTreeNode("[3, 1, 4, null, 2]"), 1) << "\n";
    std::cout << s.kthSmallest(stringToTreeNode("[5, 3, 6, 2, 4, null, null, 1]"), 3) << "\n";
}
