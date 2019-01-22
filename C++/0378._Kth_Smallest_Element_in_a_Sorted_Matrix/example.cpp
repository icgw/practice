#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;

    vector<vector<int>> matrix {
        vector<int> {  1,  5,  9 },
        vector<int> { 10, 11, 13 },
        vector<int> { 12, 13, 15 }
    };
    std::cout << s.kthSmallest(matrix, 8) << std::endl;
}
