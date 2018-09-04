/* Implement *next permutation*, which rearranges numbers into the lexicographi-
 * cally next greater permutation of numbers. If such arrangement is not possi-
 * ble, it must rearrange it as the lowest possible order (i.e., sorted in asc-
 * ending order).
 *
 * The replacement must be `in-place` and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its correspon-
 * ding outputs are in the right-hand column.
 *
 * 1, 2, 3 -> 1, 3, 2
 * 3, 2, 1 -> 1, 2, 3
 * 1, 1, 5 -> 1, 5, 1
 */ 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		static void nextPermutation(vector<int>& nums){
			int l = -1, r = -1;
			for (int i = 0; i < nums.size(); ++i){
				for (int j = i + 1; j < nums.size(); ++j){
					if (nums[j] > nums[i]) {
						if (l < i){
							l = i;
							r = j;
						} 
						else if (r > i && nums[r] > nums[j]){
							l = i;
							r = j;
						}
					}
				}
			}
			if (l != r){
				int temp;
				temp = nums[l];
				nums[l] = nums[r];
				nums[r] = temp;
				sort(nums.begin() + l + 1, nums.end());
			} else {
				sort(nums.begin(), nums.end());
			}
		}
};

int main(int argc, char* args[]){
	int a[3] = {1, 2, 3};
	int b[3] = {3, 2, 1};
	int c[3] = {1, 1, 5};
	int d[3] = {1, 3, 2};
	int e[7] = {4, 2, 0, 2, 3, 2, 0};

	vector<int> aa(a, a + 3), bb(b, b + 3), cc(c, c + 3), dd(d, d + 3),
		ee(e, e + 7);

	Solution::nextPermutation(aa);
	for (int i = 0; i < aa.size(); ++i){
		cout << aa[i] << " ";
	}
	cout << endl;

	Solution::nextPermutation(bb);
	for (int i = 0; i < bb.size(); ++i){
		cout << bb[i] << " ";
	}
	cout << endl;


	Solution::nextPermutation(cc);
	for (int i = 0; i < cc.size(); ++i){
		cout << cc[i] << " ";
	}
	cout << endl;

	Solution::nextPermutation(dd);
	for (int i = 0; i < dd.size(); ++i){
		cout << dd[i] << " ";
	}
	cout << endl;

	Solution::nextPermutation(ee);
	for (int i = 0; i < ee.size(); ++i){
		cout << ee[i] << " ";
	}
	cout << endl;

	return 0;
}
