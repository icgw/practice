#include <iostream>
#include "solution.hpp"

void run_example(){
    Solution s;
    vector<int> ans1 = s.findAnagrams("cbaebabacd", "abc");
    for (auto& x : ans1) std::cout << x << " ";
    std::cout << "\n";

    vector<int> ans2 = s.findAnagrams("abab", "ab");
    for (auto& x : ans2) std::cout << x << " ";
    std::cout << "\n";
}
