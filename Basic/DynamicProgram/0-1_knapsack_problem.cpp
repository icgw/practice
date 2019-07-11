/*
 * 0-1_knapsack_problem.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

int max(int a, int b) {
  return a > b ? a : b;
}

int knapsack_recursive(int W, int value[], int weight[], int n)
{
  if (n <= 0) return 0;

  if (weight[n - 1] > W) {
    return knapsack_recursive(W, value, weight, n - 1);
  }

  // NOTE: W - weight[n - 1]
  return max(value[n - 1] + knapsack_recursive(W - weight[n - 1], value, weight, n - 1),
             knapsack_recursive(W, value, weight, n - 1));
}

// TODO: dynamic program

int main()
{
  int n = 3, W = 50;
  int value[]  = { 60, 100, 120 };
  int weight[] = { 10, 20, 30 };

  std::cout << knapsack_recursive(W, value, weight, n) << "\n";

  return 0;
}
