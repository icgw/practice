/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */


#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int helper(int tgt, unordered_map<int, int> &memo) {
  if (0 == tgt) {
    return 0;
  }
  else if (1 == tgt) {
    return 1;
  }
  else if (memo.find(tgt) != memo.end()) {
    return memo[tgt];
  }

  double p = log2(tgt);

  int ip = static_cast<int>(p);
  if (p == static_cast<double>(ip)) {
    return 1;
  }

  int l = (1 << ip);
  int r = (1 << (ip + 1));

  int res = 1 + helper(tgt - l, memo);

  if (r - tgt < tgt) {
    res = min(res, 1 + helper(r - tgt, memo));
  }

  memo[tgt] = res;
  return res;
}

int minNumPowerTwo(int n) {
  unordered_map<int, int> memo;
  return helper(n, memo);
}

int main()
{
  int n; cin >> n;
  cout << minNumPowerTwo(n) << endl;
  return 0;
}
