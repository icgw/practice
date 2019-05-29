/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

constexpr int MAX_COLORS = 1001;

void update(int &a, int b) {
    a = min(a, b);
}

// go on thinking....
int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, K; cin >> N >> K;
    vector<int> P (N), A(N);
    for (int j = 0; j < N; ++j) cin >> P[j];
    for (int j = 0; j < N; ++j) cin >> A[j];
    vector<vector<int>> dogs (MAX_COLORS);
    for (int j = 0; j < N; ++j) {
      dogs[A[j]].push_back(P[j]);
    }
    for (int j = 0; j < N; ++j) {
      sort(dogs[A[j]].begin(), dogs[A[j]].end());
    }
    int dp[MAX_COLORS][K + 1][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][1] = dp[0][0][0] = 0;
    for (int c = 1; c < MAX_COLORS; ++c) {
      for (int k = 0; k <= K; ++k) {
        for (int b = 0; b < 2; ++b) {
          if (dp[c - 1][k][b] < 1e9) {
            update(dp[c][k][b], dp[c - 1][k][b]);
            int sz = dogs[c].size();
            for (int d = 1; d + k <= K && d <= sz; ++d) {
              update(dp[c][d + k][b], dp[c - 1][k][b] + 2 * dogs[c][d - 1]);
              if (b == 0) {
                update(dp[c][d + k][1], dp[c - 1][k][b] + dogs[c][d - 1]);
              }
            }
          }
        }
      }
    }
    cout << "Case #" << i << ": " << dp[MAX_COLORS - 1][K][1] << "\n";
  }
  return 0;
}
