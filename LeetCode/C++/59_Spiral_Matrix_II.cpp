/* Given a positive integer n, generate a square matrix filled with elements 
 * from 1 to n^2 in spiral order.
 *
 * Example:
 * 	Input: 3
 * 	Output:
 * 	[
 * 		[1, 2, 3],
 * 		[8, 9, 4],
 * 		[7, 6, 5]
 * 	]
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<vector<int>> generateMatrix(int n){
			vector<vector<int>> ans;
			for (int i = 0; i < n; ++i){
				vector<int> add (n, -1);
				ans.push_back(add);
			}
			int i = 0, j = 0;
			int k = 1;
			while (ans[i][j] == -1){
				while (j < n && ans[i][j] == -1)
					ans[i][j++] = k++;
				--j;
				++i;
				while (i < n && ans[i][j] == -1)
					ans[i++][j] = k++;
				--i;
				--j;
				while (j >= 0 && ans[i][j] == -1)
					ans[i][j--] = k++;
				++j;
				--i;
				while (i >= 0 && ans[i][j] == -1)
					ans[i--][j] = k++;
				++i;
				++j;
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	int n = 3;
	vector<vector<int>> ans = Solution::generateMatrix(n);
	for (auto& x : ans){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
