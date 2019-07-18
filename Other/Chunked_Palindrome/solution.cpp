/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
using namespace std;

int chunked_palindrome (string s) {
  int l = 0, r = s.size();
  int cnt = 0;

  int len = 1;
  while (l <= r - len) {
    if (l == r - len) {
      ++cnt;
      break;
    }

    string left  = s.substr(l, len);
    string right = s.substr(r - len, len);
    if (left == right) {
      l   += len;
      r   -= len;
      cnt += 2;
      len  = 1;
    } else {
      ++len;
    }
  }
  return cnt;
}

int main()
{
  string s1 = "a", s2 = "voabcvo", s3 = "vovo", s4 = "volvolvo", s5 = "aaaaaa", s6 = "abcbad", s7 = "volvol";

  cout << chunked_palindrome(s1) << endl;
  cout << chunked_palindrome(s2) << endl;
  cout << chunked_palindrome(s3) << endl;
  cout << chunked_palindrome(s4) << endl;
  cout << chunked_palindrome(s5) << endl;
  cout << chunked_palindrome(s6) << endl;
  cout << chunked_palindrome(s7) << endl;

  return 0;
}
