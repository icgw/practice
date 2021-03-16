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
#include <numeric>
using std::numeric_limits;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int sizeOfNum1 = nums1.size();
    int sizeOfNum2 = nums2.size();

    int len = sizeOfNum1 + sizeOfNum2;
    int iMin = 0, iMax = sizeOfNum1;

    double median1 = 0, median2 = 0;
    while (iMin <= iMax) {
      int i = iMin + (iMax - iMin) / 2;
      int j = (len + 1) / 2 - i;

      int numi1 = (i == 0) ? numeric_limits<int>::min() : nums1[i - 1];
      int numi2 = (i == sizeOfNum1) ? numeric_limits<int>::max() : nums1[i];
      int numj1 = (j == 0) ? numeric_limits<int>::min() : nums2[j - 1];
      int numj2 = (j == sizeOfNum2) ? numeric_limits<int>::max() : nums2[j];

      median1 = max(numi1, numj1);
      median2 = min(numi2, numj2);
      if (numi1 > numj2) {
        iMax = i - 1;
      }
      else if (numj1 > numi2) {
        iMin = i + 1;
      } else {
        break;
      }
    }
    return len % 2 ? median1 : (median1 + median2) / 2.0;
  }
};

#endif // ifndef _SOLUTION_HPP_
