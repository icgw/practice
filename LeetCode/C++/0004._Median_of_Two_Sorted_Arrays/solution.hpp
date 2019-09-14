/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <vector>
using std::vector;

#include <algorithm>
using std::max;
using std::min;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int lo = 0, hi = nums1.size();
    int half = (nums1.size() + nums2.size() + 1) / 2;

    while (lo <= hi) {
      int i = lo + (hi - lo) / 2;
      int j = half - i;
      if (i < hi && nums1[i] < nums2[j - 1]) {
        // NOTE: nums1[i] is too small.
        lo = i + 1;
      }
      else if (i > lo && nums1[i - 1] > nums2[j]) {
        // NOTE: nums1[i] is too big.
        hi = i - 1;
      }
      else {
        int maxLeft = 0;
        if (i == 0) {
          maxLeft = nums2[j - 1];
        }
        else if (j == 0) {
          maxLeft = nums1[i - 1];
        }
        else {
          maxLeft = max(nums1[i - 1], nums2[j - 1]);
        }

        if ( (nums1.size() + nums2.size()) % 2 == 1 ) {
          return maxLeft;
        }

        int minRight = 0;
        if (i == nums1.size()) {
          minRight = nums2[j];
        }
        else if (j == nums2.size()) {
          minRight = nums1[i];
        }
        else {
          minRight = min(nums1[i], nums2[j]);
        }

        return ( maxLeft + minRight ) / 2.0;
      }
    }

    return 0.0;
  }

/*{{{*/
  // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){ // Recursive
  //   int sz1 = nums1.size(), sz2 = nums2.size();
  //   int lm = (sz1 + sz2 + 1) / 2, rm = (sz1 + sz2 + 2) / 2;
  //   return (findKth(nums1, 0, nums2, 0, lm) + findKth(nums1, 0, nums2, 0, rm)) / 2;
  // }

  // double findKth(vector<int>& nums1, int i1, vector<int>& nums2, int i2, int k){
  //   if (i1 >= nums1.size()) return nums2[i2 + k - 1];
  //   if (i2 >= nums2.size()) return nums1[i1 + k - 1];
  //   if (k == 1) return min(nums1[i1], nums2[i2]);
  //   int v1 = i1 + k / 2 - 1 < nums1.size() ? nums1[i1 + k / 2 - 1] : INT_MAX;
  //   int v2 = i2 + k / 2 - 1 < nums2.size() ? nums2[i2 + k / 2 - 1] : INT_MAX;
  //   if (v1 < v2){
  //     return findKth(nums1, i1 + k / 2, nums2, i2, k - k / 2);
  //   } else {
  //     return findKth(nums1, i1, nums2, i2 + k / 2, k - k / 2);
  //   }
  // }
/*}}}*/
};

#endif // ifndef _SOLUTION_HPP_
