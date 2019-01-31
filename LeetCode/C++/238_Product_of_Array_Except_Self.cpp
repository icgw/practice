/* Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * Example:
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> productExceptSelf(vector<int>& nums){
			int n = nums.size(), i, pre = 1;
			vector<int> prod(n);
			for (i = prod[0] = 1; i < n; ++i) 
				prod[i] = prod[i - 1] * nums[i - 1];
			while (--i >= 0){
				prod[i] *= pre;
				pre *= nums[i];
			}
			return prod;
		}

		static vector<int> productExceptSelf_old(vector<int>& nums){
			helper(nums, 0, nums.size());
			return nums;
		}

		static int helper(vector<int>& nums, int p, int q){
			int out = 1;
			if (p == q) return out;

			for (int i = p; i < q; ++i) out *= nums[i];

			if (q - p == 1){
				nums[p] = 1;
				return out;
			}

			int m = (p + q) >> 1, l, r;
			l = helper(nums, p, m); 
			r = helper(nums, m, q);
			for (int i = p; i < m; ++i) nums[i] *= r;
			for (int i = m; i < q; ++i) nums[i] *= l;
			return out;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {1, 2, 3, 4};
	vector<int> ans = Solution::productExceptSelf(nums);
	for (auto& x : ans) cout << x << endl;
	return 0;
}
