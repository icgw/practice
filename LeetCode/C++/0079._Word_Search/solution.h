/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
private:
  bool exist(vector<vector<char>>& board, const int x, const int y, string& word, const int i) {
    int n = word.size();
    if (i == n) {
      return true;
    }
    int nrow = board.size();
    int ncol = board[0].size();
    if (i < 0 || x < 0 || y < 0 || x >= nrow || y >= ncol || board[x][y] != word[i]) {
      return false;
    }
    char tmp = board[x][y];
    board[x][y] = '#';
    bool flag = exist(board, x + 1, y, word, i + 1) ||
      exist(board, x, y + 1, word, i + 1) ||
      exist(board, x - 1, y, word, i + 1) ||
      exist(board, x, y - 1, word, i + 1);
    board[x][y] = tmp;
    return flag;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (exist(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};

#endif /* !_SOLUTION_H_ */

