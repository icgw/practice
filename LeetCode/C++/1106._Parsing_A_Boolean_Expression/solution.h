/*
 * solution.h
 * Copyright (C) 2020 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the GPL license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <string>
using std::string;

class Solution {
private:
  bool not_f(const string& expr, int& pos) {
    pos += 2; // eat '!('
    bool ret = f(expr, pos);
    ++pos; // eat ')'
    return !ret;
  }

  bool and_f(const string& expr, int& pos) {
    pos += 2; // eat '&('
    bool ret = f(expr, pos);
    while (expr[pos] != ')') {
      ++pos; // eat ','
      ret &= f(expr, pos);
    }
    ++pos; // eat ')'
    return ret;
  }

  bool or_f(const string& expr, int& pos) {
    pos += 2; // eat '&('
    bool ret = f(expr, pos);
    while (expr[pos] != ')') {
      ++pos; // eat ','
      ret |= f(expr, pos);
    }
    ++pos; // eat ')'
    return ret;
  }

  bool f(const string& expr, int& pos) {
    if (expr[pos] == 't') {
      ++pos; // eat 't'
      return true;
    }
    if (expr[pos] == 'f') {
      ++pos; // eat 'f'
      return false;
    }
    if (expr[pos] == '!') {
      return not_f(expr, pos);
    }
    if (expr[pos] == '&') {
      return and_f(expr, pos);
    }
    return or_f(expr, pos);
  }
public:
  bool parseBoolExpr(string expression) {
    int i = 0;
    return f(expression, i);
  }
};

#endif /* !_SOLUTION_H_ */

