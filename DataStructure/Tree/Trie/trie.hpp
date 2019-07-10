/*
 * trie.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _TRIE_HPP_
#define _TRIE_HPP_

#include <string>
using std::string;

constexpr int ALPHABET_SIZE = 26;

struct TrieNode {
  TrieNode * child [ALPHABET_SIZE];
  bool isEndOfWord;
};

class trie {
public:
  // TODO: insert
  void insert(string s);

  // TODO: remove

  // TODO: search
  bool search(string s);

private:
  TrieNode * root = nullptr;

  TrieNode * newTrieNode() {
    TrieNode * ret = new TrieNode;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      ret->child[i] = nullptr;
    }

    ret->isEndOfWord = false;

    return ret;
  }
};

inline
void trie::insert(string s)
{
  if (root == nullptr) {
    root = newTrieNode();
  }

  TrieNode * pNode = root;

  for (char ch : s) {
    int idx = ch - 'a';
    if (pNode->child[idx] == nullptr) {
      pNode->child[idx] = newTrieNode();
    }
    pNode = pNode->child[idx];
  }

  pNode->isEndOfWord = true;
}

inline
bool trie::search(string s)
{
  TrieNode * pNode = root;

  for (auto ch : s) {
    int idx = ch - 'a';
    if (pNode->child[idx] == nullptr) {
      return false;
    }
    pNode = pNode->child[idx];
  }

  return pNode != nullptr && pNode->isEndOfWord;
}

#endif // ifndef _TRIE_HPP_
