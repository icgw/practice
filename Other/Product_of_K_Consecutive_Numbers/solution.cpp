/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> prod_of_k_nums(vector<int> &nums, int k) {
  int n = nums.size();
  if (n < 1) return vector<int>();

  vector<int> res (n);

  // prev = (nums[l] * nums[l + 1] * .. * nums[l + k - 1]) / nums[l]
  int prev = 1;
  for (int r = 0, l = 1 - k; r < n; ++r, ++l) {
    res[r] = prev * nums[r];
    if (l < 0) {
      prev = res[r];
    } else {
      prev = res[r] / nums[l];
    }
  }

  return res;
}

int main() {
  vector<int> nums { 1, 3, 3, 6, 5, 7, 0, -3 };
  int k = 3;

  vector<int> ans = prod_of_k_nums(nums, k);

  for (int i : ans) cout << i << endl;

  return 0;
}
