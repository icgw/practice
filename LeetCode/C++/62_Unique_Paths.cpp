/* A robot is located at the top-left corner of a m x n grid (marked `Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corne of the grid (marked `Finish' in the
 * diagram below).
 *
 * How many possible unqiue paths are there?
 *
 * Note: m and will be at most 100.
 * Example:
 * 	Input: m = 3, n = 2
 * 	Ouptu: 3
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int uniquePaths(int m, int n){
			vector<int> ans(n, 1);
			while (--m > 0){
				for (int i = 1; i < n; ++i){
					ans[i] += ans[i - 1];
				}
			}

			return ans[n - 1];
		}
};

int main(int argc, char* args[]){
	int m1 = 3, n1 = 2;
	cout << Solution::uniquePaths(m1, n1) << endl;

	int m2 = 7, n2 = 3;
	cout << Solution::uniquePaths(m2, n2) << endl;

	return 0;
}
