#include <iostream>
using namespace std;

int main()
{
  int num, base;
  cin >> num >> base;

  static int arr[32] = { 0 };
  int id = 0;
  while (num > 0) {
    arr[id++] = num % base;
    num /= base;
  }

  int lo = 0, hi =  id - 1;
  bool flag = true;
  while (lo < hi) {
    if (arr[lo++] != arr[hi--]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  for (int i = id - 1; i >= 0; --i) {
    cout << arr[i];
    if (i != 0) {
      cout << " ";
    }
  }

  if (id == 0) {
    cout << arr[0];
  }
  cout << "\n";

  return 0;
}
