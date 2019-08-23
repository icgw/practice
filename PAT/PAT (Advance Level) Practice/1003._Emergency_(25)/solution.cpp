/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>

using namespace std;

int main() {
  // vector<int> teamNbOfCities;
  // vector<vector<int>> lenOfRoads;

  int nbCities, nbRoads, src, tgt;
  cin >> nbCities >> nbRoads >> src >> tgt;

  // initial number of secure team in each cities.
  vector<int> teamNbOfCities (nbCities, 0);
  for (int i = 0; i < nbCities; ++i) {
    cin >> teamNbOfCities[i];
  }

  vector<int> srcRoads (nbRoads, -1), tgtRoads (nbRoads, -1), lenRoads (nbRoads, -1);
  vector<vector<int>> edge (nbCities, vector<int>(nbCities, 0x3f3f3f3f));
  for (int i = 0; i < nbRoads; ++i) {
    int s, t, d; cin >> s >> t >> d;
    edge[s][t] = d;
    edge[t][s] = d;
  }

  vector<int> dist (nbCities, 0x3f3f3f3f);
  vector<int> gather (nbCities, 0);
  vector<int> nbOfPath (nbCities, 0);

  dist[src]     = 0;
  gather[src]   = teamNbOfCities[src];
  nbOfPath[src] = 1;

  vector<bool> seen (nbCities, false);

  // n cities not seen; (brute force)
  for (int i = 0; i < nbCities; ++i) {
    int u = -1, min_dist = 0x3f3f3f3f;
    for (int k = 0; k < nbCities; ++k) {
      if (seen[k] == false && dist[k] < min_dist) {
        u = k;
        min_dist = dist[k];
      }
    }

    if (u == -1) break;
    seen[u] = true;

    for (int v = 0; v < nbCities; ++v) {
      if (seen[v] == false && edge[u][v] < 0x3f3f3f3f) {
        if (dist[u] + edge[u][v] < dist[v]) {
          dist[v] = dist[u] + edge[u][v];
          nbOfPath[v] = nbOfPath[u];
          gather[v] = gather[u] + teamNbOfCities[v];
        } else if (dist[u] + edge[u][v] == dist[v]) {
          nbOfPath[v] = nbOfPath[u] + nbOfPath[v];
          if (gather[u] + teamNbOfCities[v] > gather[v]) {
            gather[v] = gather[u] + teamNbOfCities[v];
          }
        }
      }
    }
  }

  cout << nbOfPath[tgt] << " " << gather[tgt] << endl;

  return 0;
}
