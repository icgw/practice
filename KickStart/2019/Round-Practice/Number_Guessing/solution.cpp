/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int A, B;
    cin >> A >> B;
    int N;
    cin >> N;
    int lo = A + 1, hi = B;
    while (true) {
      int m = lo + (hi - lo) / 2;
      cout << m << endl;
      string s; cin >> s;
      if ("CORRECT" == s) {
        break;
      }
      else if ("TOO_BIG" == s) {
        hi = m - 1;
      }
      else {
        lo = m + 1;
      }
    }
  }
  return 0;
}
