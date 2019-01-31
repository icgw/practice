/* Given a matrix of m x n elements (m rows, n columns), return all elements of 
 * the matrix in spiral order.
 *
 * Example 1:
 * 	Input:
 * 	[
 * 		[1, 2, 3],
 * 		[4, 5, 6],
 * 		[7, 8, 9]
 * 	]
 * 	Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
 */ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> spiralOrder(vector<vector<int>>& matrix){
			vector<int> ans;
			int m = matrix.size();
			if (m == 0){
				return ans;
			}

			int n = matrix[0].size();
			if (n == 0){
				return ans;
			}

			for (int i = 0; i < m; ++i){
				for (int j = 0; j < n - i; ++j){
					ans.push_back(matrix[i][j]);
				}
				for (int j = i + 1; j < m && n > i; ++j){
					ans.push_back(matrix[j][n - 1 - i]);
				}
				reverse(matrix.begin() + i + 1, matrix.end());
				for (int j = i + 1; j < m; ++j){
					reverse(matrix[j].begin(), matrix[j].end() - i - 1);
				}
			}

			return ans;
		}
};

int main(int argc, char* args[]){
	int a1[4] = {1, 2, 3, 4};
	vector<int> aa1(a1, a1 + 4);

	int a2[4] = {5, 6, 7, 8};
	vector<int> aa2(a2, a2 + 4);

	int a3[4] = {9, 10, 11, 12};
	vector<int> aa3(a3, a3 + 4);

	vector<vector<int>> aa;
	aa.push_back(aa1);
	aa.push_back(aa2);
	aa.push_back(aa3);

	vector<int> aa_ans = Solution::spiralOrder(aa);
	for (auto& x : aa_ans){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
