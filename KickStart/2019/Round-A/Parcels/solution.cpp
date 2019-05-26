/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*{{{ TIme Limit Exceeded */
bool is_bound(int r, int c, int R, int C) {
  return r < 0 || c < 0 || r >= R || c >= C;
}

int search_min(vector<vector<char>> &sq, int r, int c, int R, int C) {
  static const vector<vector<int>> dirs { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

  vector<vector<bool>> visited(R, vector<bool> (C, false));
  queue<vector<int>> q;
  q.push({ r, c });

  visited[r][c] = true;
  int walk = 0;
  while (!q.empty()) {
    int sz = q.size();
    for (int k = 0; k < sz; ++k) {
      auto curr = q.front();
      if (sq[curr[0]][curr[1]] == '1') return walk;
      q.pop();
      for (auto &d : dirs) {
        int rr = curr[0] + d[0], cc = curr[1] + d[1];
        if (!is_bound(rr, cc, R, C) && !visited[rr][cc]) {
          visited[rr][cc] = true;
          q.push({ rr, cc });
        }
      }
    }
    walk++;
  }
  return walk;
}

int min_overall(vector<vector<char>> &sq, int R, int C) {
  int ret = 0;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (sq[i][j] == '1') continue;
      ret = max(ret, search_min(sq, i, j, R, C));
    }
  }
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

    int ans = 501;
    bool flag = false;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (grid[i][j] == '1') continue;
        flag = true;
        grid[i][j] = '1';
        ans = min(ans, min_overall(grid, R, C));
        grid[i][j] = '0';
      }
    }
    cout << "Case #" << i << ": " << (flag ? ans : 0) << "\n";
  }

  return 0;
}/*}}}*/
