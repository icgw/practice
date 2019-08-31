/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>
using namespace std;

bool isEvenBits(int num) {
  if (num == 0) return true;

  int cnt = 0;

  while (num != 0) {
    if ((num & 0x1) != 0) {
      ++cnt;
    }
    num >>= 1;
  }

  return (cnt % 2 == 0);
}

int countEvenBits(vector<int> nums) {
  int cnt = 0;
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    if (isEvenBits(nums[i])) {
      cnt = i + 1;
    } else {
      for (int k = 0; k < i - cnt; ++k) {
        if (isEvenBits(nums[k] ^ nums[i])) {
          cnt = i - k - 1;
          break;
        }
      }
    }
  }
  return cnt;
}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, Q; cin >> N >> Q;
    vector<int> nums ( N );

    for (int k = 0; k < N; ++k) cin >> nums[k];

    vector<int> xors ( N, 0 );
    int mask = 0;
    for (int k = 0; k < N; ++k) {
      mask   ^= nums[k];
      xors[k] = mask;
    }

    vector<int> ans ( Q );
    for (int k = 0; k < Q; ++k) {
      int idx, val;
      cin >> idx >> val;

      int m = (nums[idx] ^ val);
      nums[idx] = val;
      for (int j = idx; j < N; ++j) {
        xors[j] ^= m;
      }

      ans[k] = countEvenBits(xors);
    }

    cout << "Case #" << i << ": ";
    for (int k = 0; k < Q; ++k) {
      if (k != 0) cout << " ";
      cout << ans[k];
    }
    cout << "\n";
  }

  return 0;
}
