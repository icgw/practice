#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    string s1 = "3+2*2";
    std::cout << s.calculate(s1) << std::endl;

    string s2 = "3/2";
    std::cout << s.calculate(s2) << std::endl;

    string s3 = "3+5/2";
    std::cout << s.calculate(s3) << std::endl;
}
