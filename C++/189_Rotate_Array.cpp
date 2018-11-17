/* Given an array, rotate the array to the right by k steps, where k is 
 * non-negative.
 *
 * Example:
 *   Input: [-1, -100, 3, 99] and k = 2
 *  Output: [3, 99, -1, -100]
 *
 * Note:
 * 	+ Try to come up as many solutions as you can, there are at least 3 
 * 	  different ways to solve this problem.
 * 	+ Could you do it in-place with O(1) extra space?
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		/* static void rotate(vector<int>& nums, int k){ // Baaaaaaaaaaaaaaaad!!!
			int sz = nums.size(), res, tmp;
			while (k > 0){
				res = nums[0];
				for (int i = 1; i < sz; ++i){
					swap(nums[i], res);
				}
				nums[0] = res;
				--k;
			}
		} */

		static void rotate(vector<int>& nums, int k){
			int sz = nums.size();
			k %= sz;
			reverse(nums.begin(), nums.end());
			reverse(nums.begin(), nums.begin() + k);
			reverse(nums.begin() + k, nums.end());
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {1, 2, 3, 4, 5, 6, 7};
	int k = 3;

	Solution::rotate(nums, k);
	for (auto& x : nums){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
