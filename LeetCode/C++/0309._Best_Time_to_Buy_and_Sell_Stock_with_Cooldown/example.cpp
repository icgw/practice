#include "solution.hpp"
#include <iostream>

void run_example(){
    Solution s;
    vector<int> prices {1, 2, 3, 0, 2};
    std::cout << s.maxProfit(prices) << std::endl;
}
