/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <algorithm>
#include <cstring>
// #include <string>

using namespace std;

/*{{{ NOTE: Time Limited Exceeded. */
// bool canPalindromes(string s) {
//   if (s.empty()) return false;
//   int alpha[26] = { 0 };
//   for (auto ch : s) {
//     alpha[ch - 'A']++;
//   }
//   int odd = 0;
//   for (int i = 0; i < 26; ++i) {
//     if (alpha[i] % 2 == 1) odd++;
//   }
//   if (odd > 1) return false;
//   if (odd == 1) return s.size() % 2 == 1;
//   return true;
// }

// int main()
// {
//   int t; cin >> t;
//   for (int i = 1; i <= t; ++i) {
//     int n, q; cin >> n >> q;
//     string tmp; cin >> tmp;
//     int y = 0, l, r;
//     for (int k = 0; k < q; ++k) {
//       cin >> l >> r;
//       if (canPalindromes(tmp.substr(l - 1, r - l + 1))) y++;
//     }
//     cout << "Case #" << i << ": " << y << "\n";
//   }
//   return 0;
// } /*}}} */

int main()
{
  constexpr int MAXN = 1.1e5;
  static int numAlpha[MAXN][26];
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    memset(numAlpha, 0, sizeof(numAlpha));
    int N, Q; cin >> N >> Q;
    char ch;
    for (int j = 0; j < N; ++j) {
      cin >> ch;
      memcpy(numAlpha[j + 1], numAlpha[j], sizeof(numAlpha[j + 1]));
      ++numAlpha[j + 1][ch - 'A'];
    }
    int ans = 0;
    for (int j = 0; j < Q; ++j) {
      int L, R; cin >> L >> R;
      int tmp = 0;
      for (int z = 0; z < 26; ++z) {
        tmp += ((numAlpha[R][z] - numAlpha[L - 1][z]) & 1);
      }
      if (tmp <= 1) ++ans;
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
