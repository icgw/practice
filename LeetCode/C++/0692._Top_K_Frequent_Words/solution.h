/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <unordered_map>
using std::unordered_map;
#include <queue>
using std::priority_queue;

class Solution {
  using PIS = pair<int, string>;
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> wordToFreq;
    for (const auto& w : words) {
      ++wordToFreq[w];
    }
    auto cmp = [](const PIS& l, const PIS& r) {
      return l.first > r.first || (l.first == r.first && l.second < r.second);
    };
    priority_queue<PIS, vector<PIS>, decltype(cmp)> pq(cmp);
    for (const auto& [s, i] : wordToFreq) {
      if (pq.size() < k || i >= pq.top().first) {
        pq.emplace(i, s);
      }
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> res;
    while (k--) {
      res.emplace_back(pq.top().second);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

#endif /* !_SOLUTION_H_ */

