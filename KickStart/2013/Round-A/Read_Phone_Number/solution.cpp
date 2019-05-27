/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <sstream>
using namespace std;


string read_phone_div(const string &s)
{
  static const string num_to_word[10] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  static const string succesive[9]    = {
    "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple" };

  int sz = s.size(), cnt = 1;
  char pre = '#';
  string ret = "";
  for (int i = 0; i <= sz; ++i) {
    if (i < sz && s[i] == pre) {
      ++cnt;
    } else {
      if (i != 0) {
        ret += " ";
      }
      if (cnt >= 2 && cnt <= 10) {
        ret += succesive[cnt - 2];
        ret += " ";
      }
      else if (cnt > 10) {
        for (int k = 0; k < cnt; ++k) {
          if (k != 0) ret += " ";
          ret += num_to_word[pre - '0'];
        }
      }
      if (cnt <= 10 && pre != '#') {
        ret += num_to_word[pre - '0'];
      }
      cnt = 1;
    }
    pre = s[i];
  }

  return ret;
}

string read_phone_num(string &ph, string &d)
{
  istringstream is(d);
  int start = 0, dd;
  char dash;
  string ret = "";
  while (is >> dd) {
    string sub = read_phone_div(ph.substr(start, dd));
    start += dd;
    ret += sub;
    if (!(is >> dash)) {
      break;
    }
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T; cin >> T;

  for (int i = 1; i <= T; ++i) {
    string phone_num; cin >> phone_num;
    string divide;    cin >> divide;

    string ans = read_phone_num(phone_num, divide);

    cout << "Case #" << i << ": " << ans.substr(1) << "\n";
  }

  return 0;
}
