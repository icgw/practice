/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<int>> compress_2D_array_followup(vector<vector<int>> &A) {
  int m = A.size();
  if (m < 1) return {};
  int n = A[0].size();

  map<pair<int, int>, vector<pair<int, int>>> graph; // each node point to its child node.
  map<pair<int, int>, int> counter; // count the number of parent in the current node.
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      counter[ { r, c } ] = 0;
    }
  }

  for (int r = 0; r < m; ++r) {
    // XXX: for each rows.
    vector<int> order(n);
    for (int k = 0; k < n; ++k) order[k] = k;
    sort(order.begin(), order.end(), [&](int a, int b) -> bool {
          return A[r][a] < A[r][b];
        });
    for (int k = 0; k < n - 1; ++k) {
      graph[ { r, order[k] } ].push_back( { r, order[k + 1] } );
      counter[ { r, order[k + 1] } ] ++;
    }
  }

  for (int c = 0; c < n; ++c) {
    // XXX: for each columns.
    vector<int> order(m);
    for (int k = 0; k < m; ++k) order[k] = k;
    sort(order.begin(), order.end(), [&](int a, int b) -> bool {
          return A[a][c] < A[b][c];
        });
    for (int k = 0; k < m - 1; ++k) {
      graph[ { order[k], c } ].push_back( { order[k + 1], c } );
      counter[ { order[k + 1], c } ] ++;
    }
  }

  vector<vector<int>> res (m, vector<int>(n));
  int idx = 1;
  bool flag = true;
  while (flag) {
    vector<pair<int, int>> current_root_node;
    flag = false;
    for (map<pair<int, int>, int>::iterator it = counter.begin(); it != counter.end(); ++it) {
      if (it->second == 0) {
        flag = true;
        current_root_node.push_back( it->first );
        it->second = -1;
      }
    }
    if (flag) {
      for (auto p : current_root_node) {
        res[p.first][p.second] = idx;
        for (auto child : graph[p]) {
          counter[child]--;
        }
      }
    }
    idx++;
  }

  return res;
}

int main()
{
  vector<vector<int>> nums {
    { 20, 80, 60, 70 },
    { 11, 90, 22, 44 },
    { 33, 99, 49, 88 }
  };

  vector<vector<int>> ans = compress_2D_array_followup(nums);
  for (auto &r : ans) {
    for (auto v : r) cout << v << " ";
    cout << endl;
  }
  return 0;
}
