#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void buildTree(vector<int> &nums, vector<int> &tree, int &pos, int n) {
  if (n >= nums.size()) return ;
  buildTree(nums, tree, pos, 2 * n);
  tree[n] = nums[pos++];
  buildTree(nums, tree, pos, 2 * n + 1);
}

int main() {
  int N; cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  vector<int> tree(N + 1);
  int pos = 0;
  buildTree(nums, tree, pos, 1);
  for (int i = 1; i <= N; ++i) {
    if (i != 1) cout << " ";
    cout << tree[i];
  }
  cout << endl;
  return 0;
}