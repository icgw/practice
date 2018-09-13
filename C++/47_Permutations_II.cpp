/* Given a collection of numbers that might contain duplicates, return all
 * possible unqiue permutations.
 *
 * Example:
 * 	Input: [1, 1, 2]
 * 	Output:
 * 	[
 * 		[1, 1, 2],
 * 		[1, 2, 1],
 * 		[2, 1, 1]
 * 	]
 */ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	public: 
		static vector<vector<int>> permuteUnique(vector<int>& nums){
			if (nums.size() == 1){
				vector<vector<int>> out;
				out.push_back(nums);
				return out;
			}

			sort(nums.begin(), nums.end());

			vector<bool> added(nums.size(), false);

			vector<vector<int>> ans;
			vector<int> curr;
			DFS(ans, nums, added, curr, nums.size());
			
			return ans;
		}

		static void DFS(vector<vector<int>>& ans, vector<int>& nums, 
				vector<bool>& added, vector<int> curr, int pre){
			if (curr.size() == nums.size()){
				ans.push_back(curr);
				return;
			}

			for (int i = 0; i < nums.size(); ++i){
				if (added[i]) continue;

				if (i > 0 && nums[i] == nums[i - 1] 
						&& !added[i - 1]) continue;

				added[i] = true;
				curr.push_back(nums[i]);
				DFS(ans, nums, added, curr, i);
				curr.pop_back();
				added[i] = false;
			}
		}
};

int main(int argc, char* args[]){
	int a[3] = {1, 1, 2};
	vector<int> aa(a, a + 3);
	vector<vector<int>> a_ans;
	
	a_ans = Solution::permuteUnique(aa);
	for (auto& x : a_ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}
	cout << endl;

	int b[4] = {2, 2, 1, 1};
	vector<int> bb(b, b + 4);
	vector<vector<int>> b_ans;

	b_ans = Solution::permuteUnique(bb);
	for (auto& x : b_ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
