/* Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 	+ Integers in each row are sorted from left to right.
 * 	+ The first integer of each row is greater than the last integer of the 
 * 	  previous row.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool searchMatrix(vector<vector<int>>& matrix, int target){
			int m = matrix.size();
			if (m == 0) return false;
			int n = matrix[0].size();
			if (n == 0) return false;

			int left_r = 0, left_c = 0;
			int right_r = m - 1, right_c = n - 1;

			int r, c, t;
			while (left_r < right_r 
					|| (left_r == right_r && left_c <= right_c)){
				t = ((left_r + right_r) * n + left_c + right_c) / 2;
				r = t / n;
				c = t % n;

				if (matrix[r][c] == target) return true;

				if (matrix[r][c] < target){
					left_r = (c == n - 1 ? r + 1 : r);
					left_c = (c == n - 1 ? 0 : c + 1);
				} else {
					right_r = (c == 0 ? r - 1 : r);
					right_c = (c == 0 ? n - 1 : c - 1);
				}
			}
			return false;
		}
};

int main(int argc, char* args[]){
	vector<vector<int>> matrix(3, vector<int>(4, 0));
	matrix[0][0] = 1; matrix[0][1] = 3; matrix[0][2] = 5; matrix[0][3] = 7;
	matrix[1][0] = 10; matrix[1][1] = 11; matrix[1][2] = 16; matrix[1][3] = 20;
	matrix[2][0] = 23; matrix[2][1] = 30; matrix[2][2] = 34; matrix[2][3] = 50;

	cout << Solution::searchMatrix(matrix, 17) << endl;

	return 0;
}
