/* You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 * Note:
 * 	You have to rotate the image in-place, which means you have to modify the 
 * 	input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * 	rotation.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static void rotate(vector<vector<int>>& matrix){
			int n = matrix.size() - 1;

			if (n < 0) return;

			int ii, jj, pre, tmp, ii_tmp;
			int k;

			pre = matrix[0][0];
			for (int i = 0; i <= n / 2; ++i){
				for (int j = i; j < n - i; ++j){
					pre = matrix[i][j];
					ii = j;
					jj = n - i;
					k = 0;
					while (k < 4){
						tmp = matrix[ii][jj];
						matrix[ii][jj] = pre;
						pre = tmp;
						ii_tmp = ii;
						ii = jj;
						jj = n - ii_tmp;
						++k;
					}
				}
			}
		}
};

int main(int argc, char* args[]){
	int a1[3] = {1, 2, 3};
	vector<int> aa1(a1, a1 + 3);
	int a2[3] = {4, 5, 6};
	vector<int> aa2(a2, a2 + 3);
	int a3[3] = {7, 8, 9};
	vector<int> aa3(a3, a3 + 3);

	vector<vector<int>> aa;
	aa.push_back(aa1);
	aa.push_back(aa2);
	aa.push_back(aa3);

	for (auto& x : aa){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}
	cout << endl;

	Solution::rotate(aa);
	for (auto& x : aa){
		for (auto& xx : x){
			cout << xx << " ";
		}
		cout << endl;
	}

	return 0;
}
