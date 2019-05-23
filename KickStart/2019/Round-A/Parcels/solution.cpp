/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>
using namespace std;

int min_overall(vector<vector<char>> &sq) {
  int ret = 0;
  // TODO:

  return ret;
}

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid (R, vector<char> (C));
    for (int j = 0; j < R; ++j) {
      for (int k = 0; k < C; ++k) {
        cin >> grid[j][k];
      }
    }
    // TODO:
    int ans = min_overall(grid);
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
