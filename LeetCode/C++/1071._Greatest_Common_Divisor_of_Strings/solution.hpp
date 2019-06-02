/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <string>
using std::string;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
    if (str2.empty()) return str1;
    if (str1.substr(0, str2.size()) != str2) return "";
    return gcdOfStrings(str1.substr(str2.size()), str2);
  }
};

#endif // ifndef _SOLUTION_HPP_
