#include "solution.hpp"
#include <iostream>

void run_example(){
    Solution s;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << s.coinChange(coins1, amount1) << std::endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << s.coinChange(coins2, amount2) << std::endl;
}
