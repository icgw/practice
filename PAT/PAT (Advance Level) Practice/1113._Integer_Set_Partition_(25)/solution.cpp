#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> nums(N);
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    sum += nums[i];
  }
  
  sort(nums.begin(), nums.end());
  int min_half = 0;
  for (int i = 0; i < N / 2; ++i) {
    min_half += nums[i];
  }
  
  cout << N % 2 << " " << sum - min_half - min_half << endl;
  return 0;
}