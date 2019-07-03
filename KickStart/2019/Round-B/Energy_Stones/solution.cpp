/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Stone {
  int S, E, L;
};

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N; cin >> N;
    // vector<int> S(N), E(N), L(N);
    vector<Stone> stones(N);
    int total = 0;
    for (int j = 0; j < N; ++j) {
      cin >> stones[j].S >> stones[j].E >> stones[j].L;
      total += stones[j].S;
    }

    sort(stones.begin(), stones.end(), [](Stone &a, Stone &b) -> bool {
        // float af = ((a.L == 0) ? (1.1e5) : ((float) a.S / (float) a.L));
        // float bf = ((b.L == 0) ? (1.1e5) : ((float) b.S / (float) b.L));
        return a.S * b.L < b.S * a.L;
        // return af < bf;
        });

    int Time = 0;
    vector<int> dp(total * 2, 0);
    for (int k = 0; k < total * 2; ++k) dp[k] = 0;
    for (int j = 0; j < N; ++j) {
      for (int t = Time; t >= 0; --t) {
        dp[t + stones[j].S] = max(dp[t + stones[j].S], dp[t] + max(0, stones[j].E - t * stones[j].L));
      }
      Time += stones[j].S;
    }

    int ans = 0;
    for (int j = 0; j <= total; ++j) ans = max(ans, dp[j]);

    /*
     * vector<vector<int>> dp(total + 1, vector<int>(N + 1, 0));
     * for (int k = 1; k <= N; ++k) {
     *   for (int t = 0; t <= total - stones[k - 1].S; ++t) {
     *     int energy = stones[k - 1].E - t * stones[k - 1].L;
     *     if (energy < 0) energy = 0;
     *     for (int p = k - 1; p >= 0; --p) {
     *       dp[t + stones[k - 1].S][k] = max(dp[t + stones[k - 1].S][k], max(dp[t + stones[k - 1].S][p], dp[t][p] + energy));
     *     }
     *     if (dp[t + stones[k - 1].S][k] > ans) ans = dp[t + stones[k - 1].S][k];
     *   }
     * }
     */

    cout << "Case #" << T << ": " << ans << "\n";
  }
  return 0;
}
