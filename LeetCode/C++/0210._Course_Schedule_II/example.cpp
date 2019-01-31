#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<pair<int, int>> course1 { { 1, 0 } };
    vector<int> order1 = s.findOrder(2, course1);
    for (auto i : order1) std::cout << i << std::endl;
    std::cout << "\n";

    vector<pair<int, int>> course2 { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } };
    vector<int> order2 = s.findOrder(4, course2);
    for (auto i : order2) std::cout << i << std::endl;
    std::cout << "\n";
}
