#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<char> tasks { 'A', 'A', 'A', 'B', 'B', 'B' };
    std::cout << s.leastInterval(tasks, 2) << std::endl;
}
