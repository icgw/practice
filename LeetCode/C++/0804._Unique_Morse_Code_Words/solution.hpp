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
#include <vector>
using std::vector;
#include <set>
using std::set;

class Solution {
  string to_morse(string& s) {
    static string morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                              "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                              "-.--", "--.."
    };

    string res = "";
    for (auto ch : s) {
      res += morse[ch - 'a'];
    }
    return res;
  }

public:
  int uniqueMorseRepresentations(vector<string>& words) {
    set<string> s;
    for (auto &ss : words) {
      s.insert(to_morse(ss));
    }
    return s.size();
  }
};

#endif // ifndef _SOLUTION_HPP_
