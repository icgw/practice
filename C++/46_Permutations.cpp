/* Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 * 	Input: [1, 2, 3]
 * 	Output:
 * 	[
 * 		[1, 2, 3],
 * 		[1, 3, 2],
 * 		[2, 1, 3],
 * 		[2, 3, 1],
 * 		[3, 1, 2],
 * 		[3, 2, 1]
 * 	]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> permute(vector<int>& nums){
			vector<vector<int>> ans;

			if (nums.size() == 1){
				ans.push_back(nums);
				return ans;
			}

			vector<int> curr;
			DFS(ans, nums, curr);
			return ans;
		}

		static void DFS(vector<vector<int>>& ans, vector<int> in,
				vector<int> curr){
			if (in.size() == 2){
				vector<int> a1 = curr, a2 = curr;
				a1.push_back(in[0]);
				a2.push_back(in[1]);
				a1.push_back(in[1]);
				a2.push_back(in[0]);
				ans.push_back(a1);
				ans.push_back(a2);
				return;
			}

			for (int i = 0; i < in.size(); ++i){
				vector<int> tmp;
				for (int k = 0; k < i; ++k){
					tmp.push_back(in[k]);
				}
				for (int k = i + 1; k < in.size(); ++k){
					tmp.push_back(in[k]);
				}
				curr.push_back(in[i]);
				DFS(ans, tmp, curr);
				curr.pop_back();
			}
		}
};

int main(int argc, char* args[]){
	int a[3] = {1, 2, 3};
	vector<int> aa(a, a + 3);

	vector<vector<int>> ans = Solution::permute(aa);
	for (auto& x : ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
