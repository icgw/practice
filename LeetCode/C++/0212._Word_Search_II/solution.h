/*
 * solution.h
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
private:
  struct TrieNode {
    TrieNode* next[26];
    string word;

    TrieNode() {
      for (int i = 0; i < 26; ++i) next[i] = nullptr;
      word = "";
    }
  };

  TrieNode* buildTrieTree(vector<string>& words) {
    TrieNode* root = new TrieNode();

    for (string word : words) {
      TrieNode* p = root;
      for (char c : word) {
        int k = c - 'a';
        if (p->next[k] == nullptr) p->next[k] = new TrieNode();
        p = p->next[k];
      }
      p->word = word;
    }

    return root;
  }

  void findWordsHelper(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* p, vector<string>& res) {
    if (i < 0 || j < 0 || i >= m || j >= n
        || board[i][j] == '#' || p->next[board[i][j] - 'a'] == nullptr) return;

    char c = board[i][j];
    board[i][j] = '#';

    int k = c - 'a';

    p = p->next[k];
    if (p->word != "") {
      res.push_back(p->word);
      p->word = "";
    }

    findWordsHelper(board, i - 1, j, m, n, p, res); // up
    findWordsHelper(board, i + 1, j, m, n, p, res); // down
    findWordsHelper(board, i, j - 1, m, n, p, res); // left
    findWordsHelper(board, i, j + 1, m, n, p, res); // right

    board[i][j] = c;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;

    int m = board.size();
    if (m <= 0) return res;
    int n = board[0].size();

    TrieNode* root = buildTrieTree(words);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        findWordsHelper(board, i, j, m, n, root, res);
      }
    }

    return res;
  }
};

#endif /* !SOLUTION_H */
