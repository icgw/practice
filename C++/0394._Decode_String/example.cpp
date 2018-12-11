#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    string str;

    str = "3[a]2[bc]";
    std::cout << s.decodeString(str) << std::endl;

    str = "3[a2[c]]";
    std::cout << s.decodeString(str) << std::endl;

    str = "2[abc]3[cd]ef";
    std::cout << s.decodeString(str) << std::endl;
}
