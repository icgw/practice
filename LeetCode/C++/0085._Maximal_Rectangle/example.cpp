#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<vector<char>> matrix {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    std::cout << s.maximalRectangle(matrix) << std::endl;
}
