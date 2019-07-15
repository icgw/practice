/*
 * heapsort.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

void swap (int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// NOTO: insert i into max heap.
void heapify(int * arr, int n, int i) {
  int largest = i;
  int l = 2 * i + 1, r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }

  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }

  if (i != largest) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void build_max_heap(int * arr, int n) {
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(arr, n, i);
  }
}

void heapsort(int * arr, int n) {
  build_max_heap(arr, n);

  for (int i = n - 1; i >= 0; --i) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[] = { 10, 20, 15, 17, 9, 21 };
  int n = 6;

  heapsort(arr, n);

  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << "\n";
  }

  return 0;
}
