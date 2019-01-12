#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    std::cout << s.isAnagram("anagram", "nagaram") << std::endl;
    std::cout << s.isAnagram("rat", "car") << std::endl;
}
