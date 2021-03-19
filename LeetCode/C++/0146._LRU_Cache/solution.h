/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <list>
using std::list;
#include <utility>
using std::pair;
#include <unordered_map>
using std::unordered_map;

class LRUCache {
private:
  using LI = list<int>;
  using PIL = pair<int, LI::iterator>;
  using IPIL = unordered_map<int, PIL>;

  IPIL cache_{};
  LI used_{};
  size_t capacity_;

  void touch(int key) {
    if (cache_.find(key) == cache_.end()) return;
    auto& it = cache_[key];
    used_.erase(it.second);
    used_.push_front(key);
    it.second = used_.begin();
  }
public:
  LRUCache(int capacity) : cache_(capacity), used_(), capacity_(capacity) {}

  int get(int key) {
    if (cache_.find(key) == cache_.end()) return -1;
    auto it = cache_[key];
    touch(key);
    return it.first;
  }

  void put(int key, int value) {
    if (cache_.find(key) == cache_.end()) {
      if (cache_.size() == capacity_) {
        cache_.erase(used_.back());
        used_.pop_back();
      }
      used_.push_front(key);
    } else {
      touch(key);
    }
    cache_[key] = {value, used_.begin()};
  }
};

#endif /* !_SOLUTION_H_ */

