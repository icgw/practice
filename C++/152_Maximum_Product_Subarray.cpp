/* Given an integer array `nums', find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example:
 * 	Input:  [2, 3, -2, 4]
 * 	Output: 6
 * 	Explanation: [2, 3] has the largest product 6.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		/* static int maxProduct(vector<int>& nums){ // Bad Idea!!
			int size = nums.size();
			if (size == 0) return 0;
			int max = nums[0], prod;
			for (int i = 0; i < size; ++i){
				prod = 1;
				for (int j = i; j < size; ++j){
					prod *= nums[j];
					if (prod > max) max = prod;
				}
			}
			return max;
		} */
		static int maxProduct(vector<int>& nums){
			int size = nums.size();
			if (size == 0) return 0;
			int maxPrd = nums[0], curr;
			for (int i = 1, pmin = maxPrd, pmax = maxPrd; i < size; ++i){
				curr = nums[i];
				if (curr < 0) swap(pmin, pmax);
				pmin = min(curr, pmin * curr);
				pmax = max(curr, pmax * curr);
				maxPrd = max(maxPrd, pmax);
			}
			return maxPrd;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {2, 3, -2, 4};
	cout << Solution::maxProduct(nums) << endl;

	vector<int> nums2 {-2, 0, -1};
	cout << Solution::maxProduct(nums2) << endl;
	return 0;
}
