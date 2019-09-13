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
#include <queue>
using std::priority_queue;

class Solution {
private:
  class endEarlier {
  public:
    bool operator() (const vector<int>& a, const vector<int>& b) const {
      return a[1] > b[1];
    }
  };

public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) return 0;

    priority_queue<vector<int>, vector<vector<int>>, endEarlier> q;

    static auto startEarlier = [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] < b[0];
    };

    sort(begin(intervals), end(intervals), startEarlier);

    q.push(intervals[0]);
    for (int i = 1; i < n; ++i) {
      vector<int> interval = q.top();
      q.pop();
      if (interval[1] <= intervals[i][0]) {
        // NOTE: merge
        interval[1] = intervals[i][1];
      } else {
        // NOTE: create a new room
        q.push(intervals[i]);
      }
      q.push(interval);
    }

    return q.size();
  }
};

#endif // ifndef _SOLUTION_HPP_
