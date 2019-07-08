/*
 * mergesort.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

void merge(int arr[], int lo, int mid, int hi)
{
  int n1 = mid - lo + 1;
  int n2 = hi - mid;

  int *L = (int *) malloc (n1 * sizeof(int));
  int *R = (int *) malloc (n2 * sizeof(int));

  for (int i = lo, k = 0; i <= mid; ++i, ++k)
    L[k] = arr[i];
  for (int i = mid + 1, k = 0; i <= hi; ++i, ++k)
    R[k] = arr[i];

  // NOTE: arr[lo..hi]
  int l = 0, r = 0, k = lo;
  for ( ; l < n1 && r < n2; ++k) {
    if (L[l] <= R[r]) {
      arr[k] = L[l];
      ++l;
    } else {
      arr[k] = R[r];
      ++r;
    }
  }

  while (l < n1) arr[k++] = L[l++];
  while (r < n2) arr[k++] = R[r++];

  free(R);
  free(L);
}

void mergesort(int arr[], int lo, int hi)
{
  if (lo >= hi) return ;
  int mid = lo + (hi - lo) / 2;
  mergesort(arr, lo, mid);
  mergesort(arr, mid + 1, hi);
  merge(arr, lo, mid, hi);
}

int main()
{
  int arr[] = { 9, 1, 4, 5, 6, 8 };
  mergesort(arr, 0, 5);
  for (auto i : arr) {
    std::cout << i << "\n";
  }
  return 0;
}
