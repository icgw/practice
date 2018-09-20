/* Given two integers n and k, return all possible combinations of k numbers out
 * of 1 .. n.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> combine(int n, int k){
			vector<vector<int>> ans;

			if (k < 1) return ans;

			vector<int> pre;
			dfs(ans, n, pre, k);
			return ans;
		}

		static void dfs(vector<vector<int>>& ans, int n, 
				vector<int> pre, int k){
			if (n < k) return;

			if (n == k){
				for (int i = 1; i <= n; ++i)
					pre.push_back(i);
				ans.push_back(pre);
				return;
			}

			if (k == 1){
				for (int i = 1; i <= n; ++i){
					vector<int> add = pre;
					add.push_back(i);
					ans.push_back(add);
				}
				return;
			}

			pre.push_back(n);
			dfs(ans, n - 1, pre, k - 1);
			pre.pop_back();
			dfs(ans, n - 1, pre, k);
		}

};

int main(int argc, char* args[]){
	int n = 20, k = 16;
	vector<vector<int>> ans = Solution::combine(n, k);
	for (auto& x : ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}
	return 0;
}
