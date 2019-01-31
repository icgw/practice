/* A peak element is an element that is greater than its neighbors.
 *
 * Given an input array `nums', where `nums[i] != nums[i + 1]', find a peak
 * element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any 
 * one of the peaks is fine.
 *
 * You may imagine `nums[-1] = nums[n] = -inf.
 *
 * Example:
 * 	Input:  nums = [1, 2, 1, 3, 5, 6, 4]
 * 	Output: 1 or 5
 *
 * Note:
 * 	Your solution should be in logarithmic complexity.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int findPeakElement(vector<int>& nums){
			int n = nums.size() - 2, i = 0;
			while (i <= n && nums[i] < nums[i + 1]) ++i;
			return i;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {1, 2, 1, 3, 5, 6, 4};
	cout << Solution::findPeakElement(nums) << endl;
	return 0;
}
