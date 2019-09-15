/*
 * solution.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_

#include <map>
using std::map;

#include <string>
using std::string;

class Logger {
private:
  map<string, int> ok;

public:
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp < ok[message]) {
      return false;
    }

    ok[message] = timestamp + 10;

    return true;
  }

// private:
//   map<string, int> record;

// public:
//   [>* Initialize your data structure here. <]
//   Logger() {

//   }

//   [>* Returns true if the message should be printed in the given timestamp, otherwise returns false.
//       If this method returns false, the message will not be printed.
//       The timestamp is in seconds granularity. */
//   bool shouldPrintMessage(int timestamp, string message) {
//     if (record.find(message) == record.end()) {
//       record[message] = timestamp;
//       return true;
//     }

//     if (timestamp - record[message] >= 10) {
//       record[message] = timestamp;
//       return true;
//     }

//     return false;
//   }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

#endif // ifndef _SOLUTION_HPP_
