/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>

using namespace std;

/*{{{ NOTE: Time Limited Exceeded. */
bool canPalindromes(string s) {
  if (s.empty()) return false;
  int alpha[26] = { 0 };
  for (auto ch : s) {
    alpha[ch - 'A']++;
  }
  int odd = 0;
  for (int i = 0; i < 26; ++i) {
    if (alpha[i] % 2 == 1) odd++;
  }
  if (odd > 1) return false;
  if (odd == 1) return s.size() % 2 == 1;
  return true;
}

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, Q; cin >> N >> Q;
    string tmp; cin >> tmp;
    int y = 0, L, R;
    for (int k = 0; k < Q; ++k) {
      cin >> L >> R;
      if (canPalindromes(tmp.substr(L - 1, R - L + 1))) y++;
    }
    cout << "Case #" << i << ": " << y << "\n";
  }
  return 0;
}/*}}}*/
