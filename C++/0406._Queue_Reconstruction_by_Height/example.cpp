#include <iostream>
#include "solution.hpp"

void run_example(){
    vector<pair<int, int>> people {
        pair<int, int> {7, 0},
        pair<int, int> {4, 4},
        pair<int, int> {7, 1},
        pair<int, int> {5, 0},
        pair<int, int> {6, 1},
        pair<int, int> {5, 2}
    };
    Solution s;
    vector<pair<int, int>> ans = s.reconstructQueue(people);
    for (auto& x : ans) 
        std::cout << "[" << x.first << ", " << x.second << "]" << std::endl;
}
