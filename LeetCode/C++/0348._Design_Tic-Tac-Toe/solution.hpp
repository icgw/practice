/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

class TicTacToe {
private:
  int sz;
  vector<int> rows, cols, diags;

public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    sz = n;
    rows.resize(n, 0), cols.resize(n, 0), diags.resize(2, 0);
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    player = (player == 1 ? 1 : (-1));
    rows[row] += player, cols[col] += player;

    if (row == col) diags[0] += player;

    if (sz - row - 1 == col) diags[1] += player;

    if (player == 1 && (rows[row] == sz || cols[col] == sz || diags[0] == sz || diags[1] == sz)) {
      return 1;
    }
    else if (player == -1 && (rows[row] == -sz || cols[col] == -sz || diags[0] == -sz || diags[1] == -sz)){
      return 2;
    }

    return 0;
  }

/*
 *   vector<vector<int>> grid;
 *   int size;
 *
 *   int whoWin(int startX, int startY, int player) {
 *     bool flag = true;
 *     int n = size;
 *     for (int i = 0; i < n; ++i) {
 *       if (grid[startX][i] != player) {
 *         flag = false;
 *         break;
 *       }
 *     }
 *
 *    if (flag) return player;
 *
 *     flag = true;
 *     for (int i = 0; i < n; ++i) {
 *       if (grid[i][startY] != player) {
 *         flag = false;
 *         break;
 *       }
 *     }
 *
 *     if (flag) return player;
 *
 *     if (startX == startY) {
 *       flag = true;
 *       for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
 *         if (grid[i][j] != player) {
 *           flag = false;
 *           break;
 *         }
 *       }
 *       if (flag) return player;
 *     }
 *
 *     if (n - startX - 1 == startY) {
 *       flag = true;
 *       for (int i = n - 1, j = 0; i >= 0 && j < n; --i, ++j) {
 *         if (grid[i][j] != player) {
 *           flag = false;
 *           break;
 *         }
 *       }
 *       if (flag) return player;
 *     }
 *
 *     return 0;
 *   }
 *
 *   TicTacToe(int n) {
 *     grid = vector<vector<int>> (n, vector<int>(n, 0));
 *     size = n;
 *   }
 *
 *   int move(int row, int col, int player) {
 *     grid[row][col] = player;
 *     return whoWin(row, col, player);
 *   }
 */
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

#endif // ifndef _SOLUTION_HPP_
