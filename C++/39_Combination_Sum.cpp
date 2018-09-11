/* Given a set of candidate numbers (candidates) (without duplicates) ans a 
 * target number (target), find all unique combinations in `candidates` where
 * the candidate numbers sums to `target`.
 *
 * The same repeated number may be chosen from `candidates` unlimited number
 * of times.
 *
 * Note:
 * 	+ All numbers (including `target`) will be positive integers.
 * 	+ The solution set must not contain duplicate combinations.
 */ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// This problem worth considering.
class Solution {
	public:
		static vector<vector<int>> combinationSum(vector<int>& candidates, 
				int target){
			vector<vector<int>> ans;
			vector<int> curr;

			sort(candidates.begin(), candidates.end());
			backtracking(ans, curr, candidates, 0, target);

			return ans;
		}

		static void backtracking(vector<vector<int>>& ans, vector<int> curr, 
				vector<int>& candidates, int start, int t){

			if (t < 0)
				return;

			if (t == 0){
				ans.push_back(curr);
			}

			for (int i = start; i < candidates.size(); ++i){
				curr.push_back(candidates[i]);
				backtracking(ans, curr, candidates, i, 
						t - candidates[i]);
				curr.pop_back();
			}
		}

};

int main(int argc, char* args[]){
	int a[3] = {2, 3, 5};
	vector<int> aa(a, a + 3);

	vector<vector<int>> aa_ans = Solution::combinationSum(aa, 8);
	for (auto& x : aa_ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
