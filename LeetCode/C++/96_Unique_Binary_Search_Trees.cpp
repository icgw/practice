/* Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 *
 * Example: 3
 * Output: 5
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		// Time Limit Exceeded.
		//static int numTrees(int n){
			//if (n <= 1) return 1;
			//int s = 0;
			//for (int i = 1; i <= n; ++i){
				//s += (numTrees(i - 1) * numTrees(n - i));
			//}
			//return s;
		//}

		static int numTrees(int n){
			vector<int> dp(n + 1, 0);
			dp[0] = 1; dp[1] = 1;
			for (int i = 2; i <= n; ++i){
				for (int j = i - 1; j >= 0; --j){
					dp[i] += (dp[j] * dp[i - j - 1]);
				}
			}
			return dp.back();
		}
};

int main(int argc, char* args[]){
	int n = 19;
	cout << Solution::numTrees(n) << endl;

	return 0;
}
