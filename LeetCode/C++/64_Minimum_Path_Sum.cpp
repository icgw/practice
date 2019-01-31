/* Given a m x n grid filled with non-negative numbers, find a path from top 
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 * Example:
 * 	Input:
 * 	[
 * 		[1, 3, 1],
 * 		[1, 5, 1],
 * 		[4, 2, 1]
 * 	]
 *  Output: 7
 *  Explanation: 1->3->1->1->1
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int minPathSum(vector<vector<int>>& grid){
			int m = grid.size();
			if (m == 0)
				return 0;

			int n = grid[0].size();
			if (n == 0)
				return 0;

			for (int i = 1; i < n; ++i)
				grid[0][i] += grid[0][i - 1];

			for (int i = 1; i < m; ++i)
				grid[i][0] += grid[i - 1][0];

			for (int i = 1; i < m; ++i){
				for (int j = 1; j < n; ++j){
					grid[i][j] += (grid[i - 1][j] < grid[i][j - 1]) ?
						grid[i - 1][j] : grid[i][j - 1];
				}
			}
			return grid[m - 1][n - 1];
		}
};

int main(int argc, char* args[]){
	vector<vector<int>> a(3, vector<int>(3, 0));
	a[0][0] = 1; a[0][1] = 3; a[0][2] = 1;
	a[1][0] = 1; a[1][1] = 5; a[1][2] = 1;
	a[2][0] = 4; a[2][1] = 2; a[2][2] = 1;

	cout << Solution::minPathSum(a) << endl;

	return 0;
}
