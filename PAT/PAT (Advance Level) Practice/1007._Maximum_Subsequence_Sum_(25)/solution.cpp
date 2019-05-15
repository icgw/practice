#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int K; cin >> K;

  int left, right, cur, max_sum = -1;
  for (int i = 0, sum = 0, pre; i < K; ++i) {
    cin >> cur;
    if (0 == i)  left = cur;
    if (0 == sum) pre = cur;

    sum += cur;

    if (sum < 0) {
      sum = 0;
    }
    else if (sum > max_sum) {
      max_sum = sum;
      left    = pre;
      right   = cur;
    }
  }

  if (max_sum < 0) {
    cout << 0 << " " << left << " " << cur << "\n";
  } else {
    cout << max_sum << " " << left << " " << right << "\n";
  }

  return 0;
}