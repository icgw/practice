/*
 * solution.h
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using std::vector;

#include <algorithm>
using std::move;

#include <numeric>
using std::iota;

class Solution {
private:
  void mergeSortHelper(vector<int>& indices, int first, int last, vector<int>& nums, vector<int>& res) {
    int n = last - first;
    if (n <= 1) return;

    int mid = first + n / 2;

    mergeSortHelper(indices, first, mid,  nums, res);
    mergeSortHelper(indices, mid,   last, nums, res);

    vector<int> tempIndices(n);
    for (int i = 0, l = first, r = mid; i < n; ++i) {
      if (r >= last || (l < mid && nums[indices[l]] <= nums[indices[r]])) {
        tempIndices[i] = indices[l];
        res[indices[l]] += (r - mid);
        ++l;
      } else {
        tempIndices[i] = indices[r];
        ++r;
      }
    }

    move(tempIndices.begin(), tempIndices.end(), indices.begin() + first);
  }
public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> indices(n), result(n, 0);
    iota(indices.begin(), indices.end(), 0);

    mergeSortHelper(indices, 0, n, nums, result);

    return result;
  }
};

#endif /* !SOLUTION_H */
