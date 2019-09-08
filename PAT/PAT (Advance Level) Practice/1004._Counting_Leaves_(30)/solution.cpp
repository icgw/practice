/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  vector<vector<int>> node (N + 1, vector<int>());

  for (int i = 0; i < M; ++i) {
    int node_id, K; cin >> node_id >> K;
    for (int j = 0; j < K; ++j) {
      int child; cin >> child;
      node[node_id].push_back(child);
    }
  }

  queue<int> level;
  level.push(1);

  vector<int> res;
  while (!level.empty()) {
    int sz = level.size();
    int cnt = 0;
    for (int i = 0; i < sz; ++i) {
      int rnt = level.front();
      level.pop();

      if (node[rnt].empty()) {
        ++cnt;
      } else {
        for (int c : node[rnt]) {
          level.push(c);
        }
      }
    }
    res.push_back(cnt);
  }

  int sz = res.size();
  for (int i = 0; i < sz; ++i) {
    if ( i != 0 ) cout << " ";
    cout << res[i];
  }
  cout << "\n";

  return 0;
}
