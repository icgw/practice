/* Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * (i.e., [0, 0, 1, 2, 2, 5, 6] might become [2, 5, 6, 0, 0, 1, 2]).
 *
 * You are given a target value to search. If found in the array return `true', 
 * otherwise return `false'.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool search(vector<int>& nums, int target){
			int n = nums.size();
			if (n == 0) return false;
			if (n == 1) return nums[0] == target;
			int start = 0;
			for (int i = 1; i < n; ++i){
				if (nums[i - 1] > nums[i]){
					start = i;
					break;
				}
			}
			int lo = 0, hi = n - 1;
			int mid;
			int realMid;
			while (lo <= hi){
				mid = (lo + hi) / 2;
				realMid = (start + mid) % n;
				if (nums[realMid] == target) return true;

				if (nums[realMid] < target)
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			return false;
		}
};

int main(int argc, char* args[]){
	vector<int> nums1(7, 0);
	nums1[0] = 2; nums1[1] = 5; nums1[2] = 6; nums1[3] = 0; nums1[4] = 0;
	nums1[5] = 1; nums1[6] = 2;
	int target = 0;
	cout << Solution::search(nums1, target) << endl;

	vector<int> nums2(2, 0);
	nums2[0] = 1; nums2[1] = 3;
	int t2 = 3;
	cout << Solution::search(nums2, t2) << endl;

	vector<int> nums3(5, 1);
	nums3[0] = 3;
	int t3 = 3;
	cout << Solution::search(nums3, t3) << endl;

	vector<int> nums4(5, 2);
	nums4[3] = 0;
	int t4 = 0;
	cout << Solution::search(nums4, t4) << endl;

	return 0;
}
