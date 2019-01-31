#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    for (auto& x : s.countBits(2)) std::cout << x << " ";
    std::cout << "\n";
    for (auto& x : s.countBits(5)) std::cout << x << " ";
    std::cout << "\n";
}
