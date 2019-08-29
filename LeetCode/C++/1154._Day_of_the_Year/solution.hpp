/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_


#include <string>
using std::string;

class Solution {
public:
  int dayOfYear(string date) {
    static int month_to_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year  = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day   = stoi(date.substr(8));
    if (month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ++day;

    while (--month > 0) {
      day += month_to_day[month - 1];
    }

    return day;
  }
};

#endif // ifndef _SOLUTION_HPP_
