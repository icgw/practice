/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <vector>
#include <set>
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

int main()
{
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, Q; cin >> N >> Q;

    vector<int> nums ( N );
    set<int> siOddBits; int tmp;
    for (int k = 0; k < N; ++k) {
      cin >> tmp; nums[k] = tmp;
      if (!isEvenBits(tmp)) {
        siOddBits.insert(k);
      }
    }

    int idx, val;
    bool bPrev, bNow;
    vector<int> ans ( Q );

    for (int k = 0; k < Q; ++k) {
      cin >> idx >> val;
      bPrev = isEvenBits(nums[idx]);
      bNow  = isEvenBits(val);

      if (bPrev && !bNow) {
        siOddBits.insert(idx);
      } else if (!bPrev && bNow) {
        siOddBits.erase(idx);
      }

      int sz = siOddBits.size();
      if (sz % 2 == 0) {
        ans[k] = N;
      } else {
        ans[k] = max( *siOddBits.rbegin(), N - *siOddBits.begin() - 1 );
      }
      nums[idx] = val;
    }

    cout << "Case #" << i << ":";
    for (int k = 0; k < Q; ++k) {
      cout << " " << ans[k];
    }
    cout << "\n";
  }

  return 0;
}
