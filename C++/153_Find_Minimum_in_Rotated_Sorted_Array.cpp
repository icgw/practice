/* Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example:
 * 	Input: [3, 4, 5, 1, 2]
 * 	Output: 1
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int findMin(vector<int>& nums){
			int lo = 0, hi = nums.size() - 1, mid;
			while (lo < hi){
				mid = (lo + hi) / 2;
				if (nums[lo] > nums[mid]) 
					hi = mid;
				else if (nums[mid] > nums[hi]) 
					lo = mid + 1;
				else break;
			}
			return nums[lo];
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {3, 4, 5, 1, 2};
	cout << Solution::findMin(nums) << endl;

	vector<int> nums2 {3, 1, 2};
	cout << Solution::findMin(nums2) << endl;

	return 0;
}
