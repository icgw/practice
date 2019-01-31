/* Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 */ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> subsetsWithDup(vector<int>& nums){
			int n = nums.size();
			vector<vector<int>> ans;
			if (n < 1) return ans;

			sort(nums.begin(), nums.end());
			vector<int> curr;
			dfs(ans, nums, curr, 0, nums[0] - 1);
			set<vector<int>> ans_filter;
			for (auto& x : ans){ // Bad idea
				ans_filter.insert(x);
			}
			vector<vector<int>> ans_t;
			for (auto& x : ans_filter){ // Bad idea
				ans_t.push_back(x);
			}

			return ans_t;
		}

		static void dfs(vector<vector<int>>& ans, vector<int>& nums,
				vector<int> curr, int start, int pre){
			if (nums.size() <= start) return;
			if (start == nums.size() - 1){
				ans.push_back(curr);
				curr.push_back(nums[start]);
				ans.push_back(curr);
			}

			dfs(ans, nums, curr, start + 1, nums[start]);
			curr.push_back(nums[start]);
			dfs(ans, nums, curr, start + 1, nums[start]);
		}
};

int main(int argc, char* args[]){
	vector<int> nums1(3, 0);
	nums1[0] = 1; nums1[1] = 2; nums1[2] = 2;
	vector<vector<int>> ans1 = Solution::subsetsWithDup(nums1);
	for (auto& x : ans1){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
