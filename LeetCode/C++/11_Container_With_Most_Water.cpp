/* Given n non-negative integers a_1, a_2, ..., a_n, where each represents a 
 * point at coordinate (i, a_i). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, a_i) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 */ 
#include <iostream>
#include <vector>
using namespace std;


class Solution {
	public:
		static int maxArea(vector<int>& height) {
			int max = 0, tmp;
			for (int i = 0; i < height.size(); ++i){
				for (int j = i + 1; j < height.size(); ++j){
					tmp = min(height[i], height[j]) * (j - i);
					if (tmp > max)
						max  = tmp;
				}
			}
			return max;
		}
};

int main (int argc, char *args[]) {
	int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> aa(a, a + 9);

	cout << Solution::maxArea(aa) << endl;
	Solution::maxArea(aa);

	return 0;
}
