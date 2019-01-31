/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * Example:
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool searchMatrix(vector<vector<int>>& matrix, int target){
			return dfs(matrix, target, 0);
		}

		static bool dfs(vector<vector<int>>& matrix, int tgt,
				int rowi){
			if (rowi >= matrix.size()) return false;
			if (binary_search(matrix[rowi].begin(), matrix[rowi].end(), tgt)) 
				return true;
			return dfs(matrix, tgt, rowi + 1);
		}
};

int main(int argc, char *argv[]){
	vector<vector<int>> matrix = {
		{1, 4, 7, 11, 15},
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	cout << Solution::searchMatrix(matrix, 5) << endl;
	cout << Solution::searchMatrix(matrix, 20) << endl;
	return 0;
}
