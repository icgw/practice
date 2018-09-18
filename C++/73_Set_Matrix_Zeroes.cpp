/* Given a m x n matrix, if an element is 0, set its entire row and column to 0.
 * Do it in-place.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static void setZeroes(vector<vector<int>>& matrix){
			int m = matrix.size();
			if (m == 0)
				return;
			int n = matrix[0].size();

			for (int i = 0; i < m; ++i){
				for (int j = 0; j < n; ++j){
					if (matrix[i][j] != 0)
						continue;

					for (int k = 0; k < m; ++k){
						if (matrix[k][j] == 0)
							continue;
						matrix[k][j] = -999; // Bad idea...
					}
					for (int k = 0; k < n; ++k){
						if (matrix[i][k] == 0)
							continue;
						matrix[i][k] = -999;
					}
				}
			}
			for (int i = 0; i < m; ++i){
				for (int j = 0; j < n; ++j){
					if (matrix[i][j] == -999)
						matrix[i][j] = 0;
				}
			}
		}
};

int main(int argc, char* args[]){
	vector<vector<int>> a(3, vector<int>(4, 0));
	a[0][1] = 1; a[0][2] = 2;
	a[1][0] = 3; a[1][1] = 4; a[1][2] = 5; a[1][3] = 2;
	a[2][0] = 1; a[2][1] = 3; a[2][2] = 1; a[2][3] = 5;
	Solution::setZeroes(a);
	for (auto& x : a){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
