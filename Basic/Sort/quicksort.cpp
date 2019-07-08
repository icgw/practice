/*
 * quicksort.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int partition(int arr[], int lo, int hi)
{
  int pivot = arr[hi];
  int j = lo;
  for (int i = lo; i < hi; ++i) {
    if (arr[i] < pivot) {
      swap(arr[i], arr[j]);
      ++j;
    }
  }
  swap(arr[j], arr[hi]);
  return j;
}

// NOTE: 0 <= lo, hi < arr.length()
void quicksort(int arr[], int lo, int hi)
{
  // NOTE: Don't forget.
  if (lo >= hi) return;

  int p = partition(arr, lo, hi);
  quicksort(arr, lo, p - 1);
  quicksort(arr, p + 1, hi);
}

int main()
{
  int arr[] = { 3, 1, 2, 5, 6, 9, 8 };
  quicksort(arr, 0, 6);
  for (auto a : arr) {
    std::cout << a << "\n";
  }
  return 0;
}

