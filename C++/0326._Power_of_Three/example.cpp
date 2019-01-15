#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.isPowerOfThree(27) << std::endl;
    std::cout << s.isPowerOfThree(0) << std::endl;
    std::cout << s.isPowerOfThree(9) << std::endl;
    std::cout << s.isPowerOfThree(45) << std::endl;
}
