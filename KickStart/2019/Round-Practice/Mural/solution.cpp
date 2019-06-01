/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N; cin >> N;
    vector<char> mural_score (N);
    for (int j = 0; j < N; ++j) {
      cin >> mural_score[j];
    }
    int head = 0, tail = (N + 1) / 2;
    int maximum = 0;
    for (int j = head; j < tail; ++j) {
      maximum += static_cast<int>(mural_score[j] - '0');
    }
    int tmp = maximum;
    for (int left = head, right = tail;
        left < N && right < N;
        ++left, ++right) {
      tmp += static_cast<int>(mural_score[right] - '0');
      tmp -= static_cast<int>(mural_score[left] - '0');
      if (tmp > maximum) {
          maximum = tmp;
      }
    }
    cout << "Case #" << i << ": " << maximum << "\n";
  }
  return 0;
}
