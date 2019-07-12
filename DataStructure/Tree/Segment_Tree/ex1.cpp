/*
 * ex1.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <cmath>

int constructST_core(int arr[], int s, int e, int * st, int pos) {
  if (s > e) return 0;

  if (s == e) {
    st[pos] = arr[s];
    return st[pos];
  }

  int mid = s + (e - s) / 2;

  st[pos] = constructST_core(arr, s, mid, st, 2 * pos + 1) + constructST_core(arr, mid + 1, e, st, 2 * pos + 2);

  return st[pos];
}

// Consturct array representing the segment tree.
int * constructST(int arr[], int n) {
  int height = ceil(log2(n));
  int tree_max_size = 2 * ((int) pow(2, height)) - 1;

  int * st = (int *) malloc(tree_max_size * sizeof(int));

  constructST_core(arr, 0, n - 1, st, 0);

  return st;
}

int get_sum_core(int st[], int s, int e, int l, int r, int pos) {
  if (l <= s && e <= r) {
    return st[pos];
  }

  if (r < s || e < l) {
    return 0;
  }

  int mid = s + (e - s) / 2;
  return get_sum_core(st, s, mid, l, r, 2 * pos + 1) + get_sum_core(st, mid + 1, e, l, r, 2 * pos + 2);
}

int get_sum(int st[], int n, int l, int r) {
  if (l > r) return -1;
  return get_sum_core(st, 0, n - 1, l, r, 0);
}

// TODO: update value.

int main()
{
  int arr[] = { 1, 3, 5, 7, 9, 11 }, n = 6;

  int * segment_tree = constructST(arr, n);

  std::cout << "Sum of values in given range = " << get_sum(segment_tree, n, 1, 3) << "\n";

  return 0;
}
