/* A robot is located at the top-left corner of a m x n grid (marked `Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot 
 * is trying to reach the bottom-right corner of the grid (marked `Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Note: m and n will be at most 100.
 *
 * Example:
 * 	Input:
 * 	[
 * 		[0, 0, 0],
 * 		[0, 1, 0],
 * 		[0, 0, 0]
 * 	]
 * 	Output: 2
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
			int m = obstacleGrid.size();
			if (m == 0){
				return 0;
			}

			int n = obstacleGrid[0].size();
			if (n == 0){
				return 0;
			}

			int d = 0, r = 0;
			while (r < n && obstacleGrid[0][r] != 1){
				obstacleGrid[0][r++] = -1;
			}
			while (d < m && obstacleGrid[d][0] != 1){
				obstacleGrid[d++][0] = -1;
			}

			int up, left;
			for (int i = 1; i < m; ++i){
				for (int j = i; j < n; ++j){
					if (obstacleGrid[i][j] == 1)
						continue;
					up = obstacleGrid[i - 1][j] == 1 ? 
						0 : obstacleGrid[i - 1][j];
					left = obstacleGrid[i][j - 1] == 1 ?
						0 : obstacleGrid[i][j - 1];
					obstacleGrid[i][j] = up + left;
				}
				for (int j = i + 1; j < m && i < n; ++j){
					if (obstacleGrid[j][i] == 1)
						continue;
					up = obstacleGrid[j - 1][i] == 1 ? 
						0 : obstacleGrid[j - 1][i];
					left = obstacleGrid[j][i - 1] == 1 ?
						0 : obstacleGrid[j][i - 1];
					obstacleGrid[j][i] = up + left;
				}
			}

			if (obstacleGrid[m - 1][n - 1] == 1){
				return 0;
			}

			return -obstacleGrid[m - 1][n - 1];
		}
};

int main(int argc, char* args[]){
	vector<vector<int>> a(5, vector<int>(4, 0));
	a[1][1] = 1;
	a[3][2] = 1;
	cout << Solution::uniquePathsWithObstacles(a) << endl;

	vector<vector<int>> b(100, vector<int>(1, 0));
	b[1][0] = 1;
	cout << Solution::uniquePathsWithObstacles(b) << endl;

	vector<vector<int>> c(2, vector<int>(2, 0));
	c[0][1] = 1;
	cout << Solution::uniquePathsWithObstacles(c) << endl;

	return 0;
}
