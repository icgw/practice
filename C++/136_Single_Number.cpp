/* Given a non-empty array of integers, every element appears twice except for 
 * one. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example:
 * 	Input:  [4, 1, 2, 1, 2]
 * 	Output: 4
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		/* static int singleNumber(vector<int>& nums){ // Bad Idea!!!
			int n = nums.size(), curr;
			bool flag;
			for (int i = 0; i < n; ++i){
				curr = nums[i];
				flag = true;
				for (int k = 0; k < i; ++k){
					if (curr == nums[k]){
						flag = false;
						break;
					}
				}
				for (int k = i + 1; k < n; ++k){
					if (curr == nums[k]){
						flag = false;
						break;
					}
				}
				if (flag) return nums[i];
			}
			return 0;
		} */

		static int singleNumber(vector<int>& nums){
			int ans = 0, n = nums.size();
			for (int i = 0; i < n; ++i) ans ^= nums[i];
			return ans;
		}
};

int main(int argc, char* argv[]){
	vector<int> nums {4, 1, 2, 1, 2};
	cout << Solution::singleNumber(nums) << endl;

	return 0;
}
