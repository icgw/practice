#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    vector<string> emails { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
    std::cout << s.numUniqueEmails(emails) << std::endl;
}
