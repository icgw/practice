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

int CurMaxSubBoard(vector<vector<int>> &board, int r, int c, int R, int C, int K)
{
  int ret = 1;

  int prev_CC = C;
  for (int i = r; i < R; ++i) {
    int min_thk, max_thk;
    min_thk = max_thk = board[i][c];
    int CC = c;
    for (int j = c; j < C; ++j) {
      if (board[i][j] < min_thk) min_thk = board[i][j];
      if (board[i][j] > max_thk) max_thk = board[i][j];
      if (max_thk - min_thk <= K) CC++;
      if (CC >= prev_CC) break;
    }
    prev_CC = min(CC, prev_CC);
    ret = max(ret, (i - r + 1) * (prev_CC - c));
    if (ret > (R - r) * (prev_CC - c)) break;
  }

  return ret;
}

int MaxSubBoard(vector<vector<int>> &board, int R, int C, int K)
{
  int ret = 0;

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (ret > (R - i) * (C -j)) break;
      ret = max(CurMaxSubBoard(board, i, j, R, C, K), ret);
    }
    if (ret > (R - i) * C) break;
  }

  return ret;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int R, C, K;
    cin >> R >> C >> K;

    vector<vector<int>> board (R, vector<int>(C));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        cin >> board[r][c];
      }
    }

    int ans = MaxSubBoard(board, R, C, K);
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
