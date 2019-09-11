/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <functional>
using std::greater;

#include <queue>
using std::priority_queue;

#include <vector>
using std::vector;

class MedianFinder {
/*{{{ Brute force: TLE */
// private:
//   vector<int> nums;
//   int p;
//   bool isEven;
// public:
//   MedianFinder() {
//     p      = -1;
//     isEven = true;
//   }

//   void addNum(int num) {
//     nums.push_back(num);
//     if (isEven) {
//       isEven = false;
//       ++p;
//     } else {
//       isEven = true;
//     }
//   }

//   double findMedian() {
//     if (p == -1) return 0.0;
//     sort(nums.begin(), nums.end());
//     if (isEven) {
//       return static_cast<double>(nums[p] + nums[p + 1]) / 2.0;
//     }

//     return static_cast<double>(nums[p]);
//   }
/*}}}*/
private:
  priority_queue<int> small;
  priority_queue<int, vector<int>, greater<int>> large;

public:
  MedianFinder() {
  }

  void addNum(int num) {
    small.push(num);
    large.push(small.top());
    small.pop();
    if (small.size() < large.size()) {
      small.push(large.top());
      large.pop();
    }
  }

  double findMedian() {
    if (small.size() > large.size()) {
      return small.top();
    }
    return (small.top() + large.top()) / 2.0;
  }
};

#endif // ifndef _SOLUTION_HPP_
