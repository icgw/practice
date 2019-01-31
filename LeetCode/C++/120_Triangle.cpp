/* Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 *
 * The minimum path sum from top to bottom is `11' (i.e., 2 + 3 + 5 + 1 = 11).
 * Note:
 * 	Bonus point if you are able to do this using only O(n) extra space, where n
 * 	is the total number of rows in the triangle.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int minimumTotal(vector<vector<int>>& triangle){
			int n = triangle.size();
			if (n <= 0) return 0;
			vector<int> ans(n, 0);
			ans[0] = triangle[0][0];
			for (int i = 1; i < n; ++i){
				ans[i] = ans[i - 1] + triangle[i][i];
				for (int j = i - 1; j > 0; --j){
					ans[j] = (ans[j - 1] < ans[j]) ? 
						(ans[j - 1] + triangle[i][j]) :
						(ans[j] + triangle[i][j]);
				}
				ans[0] += triangle[i][0];
			}
			int min = ans[0];
			for (int i = 1; i < n; ++i) if (ans[i] < min) min = ans[i];
			return min;
		}
};

int main(int argc, char* argv[]){
	vector<vector<int>> tri;
	tri.push_back({2});
	tri.push_back({3, 4});
	tri.push_back({6, 5, 7});
	tri.push_back({4, 1, 8, 3});
	int min = Solution::minimumTotal(tri);
	cout << min << endl;
	return 0;
}

