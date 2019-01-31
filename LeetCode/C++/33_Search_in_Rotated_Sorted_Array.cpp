/* Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., `[0, 1, 2, 4, 5, 6, 7]` might become `[4, 5, 6, 7, 0, 1, 2]`).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return `-1`.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int search(vector<int>& nums, int target) {
			if (nums.size() == 0)
				return -1;

			int l = 0, r = nums.size() - 1;
			int l_val = nums[0], r_val = nums[r];
			if (l_val < r_val){
				return binarySearch(nums, l, r, target);
			}

			if (l_val == target)
				return 0;

			if (r_val == target)
				return r;

			int m;
			while (l < r - 1){
				m = (l + r) / 2;
				if (nums[m] > l_val){
					l = m;
				}
				if (nums[m] < r_val){
					r = m;
				}
			}

			if (target > nums[l])
				return -1;

			if (target < nums[r])
				return -1;

			int ll = 0, rr = l;
			int ans = binarySearch(nums, ll, rr, target);
			if (ans != -1)
				return ans;

			ll = r, rr = nums.size() - 1;
			ans = binarySearch(nums, ll, rr, target);

			return ans;
		}

		static int binarySearch(vector<int> nums, int l, int r, int tgt){
			if (tgt < nums[l] || tgt > nums[r])
				return -1;

			int m;
			while (l < r){
				m = (l + r) / 2;
				if (l == r - 1){
					if (nums[l] == tgt)
						return l;
					if (nums[r] == tgt)
						return r;
					return -1;
				}

				if (nums[m] < tgt){
					l = m;
				}
				else if (nums[m] > tgt){
					r = m;
				}
				else 
					break;
			}
			return m;
		}
};

int main(int argc, char* args[]){
	int a[7] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> aa(a, a + 7);

	int b[1] = {1};
	vector<int> bb(b, b + 1);

	cout << Solution::search(aa, 6) << endl;
	cout << Solution::search(bb, 1) << endl;

	return 0;
}
