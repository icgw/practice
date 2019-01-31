/* Given a 2d grid map of `1's (land) and `0's (water), count the number of 
 * islands. An island is surrounded by water and is formed by connecting 
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example:
 *  Input:
 *  11000
 *  11000
 *  00100
 *  00011
 * Output: 3
 */
#include <iostream>
#include <vector>

using namespace std;

static int dr[4] = {0, 0, -1, 1};
static int dc[4] = {-1, 1, 0, 0};

class Solution {
	public:
		static int numIslands(vector<vector<char>>& grid){
			int rows = grid.size();
			if (rows == 0) return 0;
			int columns = grid[0].size();
			int ans = 0;
			for (int i = 0; i < rows; ++i){
				for (int j = 0; j < columns; ++j){
					if (grid[i][j] == '0') continue;
					++ans;
					dfs(grid, i, j, rows, columns);
				}
			}
			return ans;
		}

		static void dfs(vector<vector<char>>& grid, 
				int i, int j,
				int m, int n){
			grid[i][j] = '0';
			for (int k = 0; k < 4; ++k){
				if (!isBound(i + dr[k], j + dc[k], m, n)
						&& grid[i + dr[k]][j + dc[k]] == '1'){
					dfs(grid, i + dr[k], j + dc[k], m, n);
				}
			}
		}

		static bool isBound(int i, int j, int m, int n){
			return i < 0 || j < 0 || i >= m || j >= n;
		}
};

int main(int argc, char *argv[]){
	vector<vector<char>> grid {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};

	cout << Solution::numIslands(grid) << endl;

	return 0;
}
