/* Given a 2D binary matrix filled with 0's and 1's, find the largest square 
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int maximalSquare(vector<vector<char>>& matrix){
			int rows = matrix.size();
			if (rows == 0) return 0;
			int columns = matrix[0].size();
			vector<int> dp (columns + 1, 0);
			int pre = 0, maxSize = 0, tmp;
			for (int i = 0; i < rows; ++i){
				for (int j = 1; j <= columns; ++j){
					if (matrix[i][j - 1] == '1'){
						tmp = dp[j];
						dp[j] = min(dp[j - 1], min(dp[j], pre)) + 1;
						pre = tmp;
						maxSize = max(dp[j], maxSize);
					} else {
						tmp = dp[j];
						dp[j] = 0;
						pre = tmp;
					}
				}
			}
			return maxSize * maxSize;
		}
};

int main(int argc, char *argv[]){
	vector<vector<char>> matrix {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};
	cout << Solution::maximalSquare(matrix) << endl;
	return 0;
}
