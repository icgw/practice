#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<vector<int>> board {
        vector<int> { 0, 1, 0 },
        vector<int> { 0, 0, 1 },
        vector<int> { 1, 1, 1 },
        vector<int> { 0, 0, 0 }
    };

    s.gameOfLife(board);
    for (auto row : board) {
        for (auto c : row) std::cout << c << " ";
        std::cout << "\n";
    }
}
