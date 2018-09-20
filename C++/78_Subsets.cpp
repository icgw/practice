/* Given a set of distinct integers, nums, return all possible subsets
 * (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 * 	Input: nums = [1, 2, 3]
 * 	Output:
 * 	[
 * 		[3],
 * 		[1],
 * 		[2],
 * 		[1, 2, 3],
 * 		[1, 3],
 * 		[2, 3],
 * 		[1, 2],
 * 		[]
 * 	]
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> subsets(vector<int>& nums){
			int size = nums.size();
			int n = (1 << size);
			vector<vector<int>> ans;
			for (int i = 0; i < n; ++i){
				vector<int> add;
				for (int j = 0; j < size; ++j){
					if (i & (1 << j)){
						add.push_back(nums[j]);
					}
				}
				ans.push_back(add);
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	vector<int> nums(3, 0);
	nums[0] = 1; nums[1] = 2; nums[2] = 3;

	vector<vector<int>> ans = Solution::subsets(nums);
	for (auto& x : ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
