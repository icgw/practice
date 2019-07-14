/*
 * stack.hpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <cstdlib>

static constexpr int M = 10;

class stack {
public:
  stack();
  stack(int size);
  ~stack();

  void push(int n);
  int  pop();
  int  top();

private:
  int * _arr    = nullptr;
  int _top      = -1;
  int _capacity = 0;

  bool isFull();
  bool isEmpty();
};

bool stack::isFull() {
  return _top >= _capacity - 1;
}

bool stack::isEmpty() {
  return _top <= -1;
}

stack::stack() {
  _arr      = (int *) malloc(M * sizeof(int));
  _top      = -1;
  _capacity = M;
}

stack::stack(int size) {
  _arr      = (int *) malloc(size * sizeof(int));
  _top      = -1;
  _capacity = size;
}

stack::~stack() {
  if (_arr != nullptr) {
    free(_arr);
    _arr = nullptr;
  }
}

inline
void stack::push(int n) {
  if (isFull()) {
    // TODO: throw an exception.
  }
  _arr[++_top] = n;
}

inline
int stack::pop() {
  if (isEmpty()) {
    // TODO: throw an exception.
  }
  return _arr[_top--];
}

inline
int stack::top() {
  if (isEmpty()) {
    // TODO: throw an exception.
  }
  return _arr[_top];
}

#endif // ifndef _STACK_HPP_
