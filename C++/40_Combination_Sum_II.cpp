/* Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in `candidates` where the candidate
 * numbers sum to `target`.
 *
 * Each number in `candidates` may only be used once in the combination.
 *
 * Note:
 * 	+ All numbers (including `target`) will be positive integers.
 * 	+ The solutiono set must not contain duplicate combinations.
 */ 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> combinationSum2(vector<int>& candidates, 
				int target){
			vector<vector<int>> ans;

			set<vector<int>> s_ans;
			vector<int> curr;
			sort(candidates.begin(), candidates.end());
			DFS(s_ans, curr, candidates, 0, target);
			for (auto& x : s_ans){
				ans.push_back(x);
			}

			return ans;
		}

		static void DFS(set<vector<int>>& ans, vector<int> curr,
				vector<int>& candidates,
				int start, int target){
			if (target < 0){
				return;
			}
			else if (target == 0){
				ans.insert(curr);
				return;
			}
			else {
				for (int i = start; i < candidates.size(); ++i){
					curr.push_back(candidates[i]);
					DFS(ans, curr, candidates, i + 1, target - candidates[i]);
					curr.pop_back();
				}
			}
		}
};

int main(int argc, char* args[]){
	int a[5] = {2, 5, 2, 1, 2};
	vector<int> aa(a, a + 5);
	int at = 5;

	vector<vector<int>> a_ans = Solution::combinationSum2(aa, at);
	for (auto& x : a_ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
