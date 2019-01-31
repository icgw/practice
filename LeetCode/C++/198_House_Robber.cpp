/* You are a professional robber planning to rob houses along a street. Each 
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security system 
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of 
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Example:
 *   Input: [2, 7, 9, 3, 1]
 *  Output: 12
 *  Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and 
 *               rob house 5 (money = 10. 
 *               Total amount you can rob = 2 + 9 + 1 = 12.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int rob(vector<int>& nums){
			int n = nums.size();
			vector<int> dp(n + 2, 0);
			for (int i = 2; i <= n + 1; ++i){
				dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2]);
			}
			return dp.back();
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {2, 7, 9, 3, 1};
	cout << Solution::rob(nums) << endl;
	return 0;
}
