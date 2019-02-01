#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, p; cin >> N >> p;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) cin >> nums[i];
  
  sort(nums.begin(), nums.end());
  
  int result = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + result; j < N; ++j) {
      long long mp = (long long) nums[i] * p;
      if (nums[j] <= mp)
        result = j - i + 1;
      else
        break;
    }
  }
  cout << result;
  
  return 0;
}