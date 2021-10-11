/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <set>
using std::multiset;
#include <map>
using std::map;

class StockPrice {
private:
  map<int, int> _timestamp_to_price;
  multiset<int> _prices;
public:
  StockPrice() {}

  void update(int timestamp, int price) {
    if (_timestamp_to_price.find(timestamp) != _timestamp_to_price.end()) {
      int prev_price = _timestamp_to_price[timestamp];
      _prices.erase(_prices.find(prev_price));
    }
    _timestamp_to_price[timestamp] = price;
    _prices.insert(price);
  }

  int current() {
    return _timestamp_to_price.rbegin()->second;
  }

  int maximum() {
    return *_prices.rbegin();
  }

  int minimum() {
    return *_prices.begin();
  }
};

#endif /* !_SOLUTION_H_ */

