#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    string J1 = "aA", S1 = "aAAbbbb";
    std::cout << s.numJewelsInStones(J1, S1) << std::endl;

    string J2 = "z", S2 = "ZZ";
    std::cout << s.numJewelsInStones(J2, S2) << std::endl;
}
