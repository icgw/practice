/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int nextMinDistance(vector<bool> seen, vector<int> dist, vector<vector<int>> graph, int n) {
  int min_dist = numeric_limits<int>::max();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (seen[i] && !seen[j] && dist[i] < numeric_limits<int>::max() && graph[i][j] < numeric_limits<int>::max()) {
        int tmp = dist[i] + graph[i][j];
        if (tmp < min_dist) {
          min_dist = tmp;
        }
      }
    }
  }

  return min_dist;
}

bool isMinDistance(vector<bool> seen, vector<int> dist, vector<vector<int>> graph, int n, int v, int min_dist) {
  for (int i = 1; i <= n; ++i) {
    if (!seen[i]) continue;
    if (dist[i] < numeric_limits<int>::max() && graph[i][v] < numeric_limits<int>::max()) {
      if (dist[i] + graph[i][v] == min_dist) return true;
    }
  }
  return false;
}

bool isDijkstraSeq(vector<vector<int>> graph, vector<int> query, int numOfVertex) {
  vector<int> dist ( numOfVertex + 1, numeric_limits<int>::max() );
  vector<bool> seen ( numOfVertex + 1, false);
  dist[query[0]] = 0;
  seen[query[0]] = true;
  int n = query.size();
  for (int i = 1; i < n; ++i) {
    int next_min_dist = nextMinDistance(seen, dist, graph, n);

    if (!isMinDistance(seen, dist, graph, n, query[i], next_min_dist)) return false;

    dist[query[i]] = next_min_dist;
    seen[query[i]] = true;
  }

  return true;
}

int main()
{
  int Nv, Ne; cin >> Nv >> Ne;
  vector<vector<int>> graph (Nv + 1, vector<int>( Nv + 1, numeric_limits<int>::max() ));
  for (int i = 0; i < Ne; ++i) {
    int h, t, w;
    cin >> h >> t >> w;
    graph[h][t] = w;
    graph[t][h] = w;
  }

  int K; cin >> K;
  for (int i = 0; i < K; ++i) {
    vector<int> q ( Nv );
    for (int j = 0; j < Nv; ++j) {
      cin >> q[j];
    }

    bool bRes = isDijkstraSeq(graph, q, Nv);
    if (bRes) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
