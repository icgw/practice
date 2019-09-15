/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

class Codec {
private:
  int find_first_start_of(string s, int pos) {
    int n = s.size();
    for (int i = pos; i < n; ++i) {
      if (s[i] == '#') return i + 1;
    }
    return n;
  }

public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string res = "";
    for (string s : strs) {
      res += (to_string(s.size()) + "#" + s);
    }
    return res;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    int i = 0, n = s.size();
    vector<string> res;
    while (i < n) {
      int start = find_first_start_of(s, i);
      int len   = stoi(s.substr(i, start - i));

      res.push_back(s.substr(start, len));
      i = start + len;
    }
    return res;
  }
};

#endif // ifndef _SOLUTION_HPP_
