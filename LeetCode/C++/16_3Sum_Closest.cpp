/* Given an array `nums` of n integers and an integer `target`, find three inte-
 * ger in `nums` such that the sum is closest to `target`. Return the sum of the
 * three integers. You may assume that each input would have exactly one solu-
 * tion.
 */ 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		static int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int size = nums.size();
			int t, a, z;
			int ans = INT_MAX;
			int cur;
			for (int i = 0; i < size - 2; ++i){
				t = nums[i] - target;
				a = i + 1;
				z = size - 1;
				while (a < z) {
					cur = t + nums[a] + nums[z];
					if (cur < 0){
						if (abs(cur) < abs(ans)){
							ans = cur;
						}
						++a;
					}

					if (cur == 0){
						ans = 0;
						break;
					}

					if (cur > 0){
						if (abs(cur) < abs(ans)){
							ans = cur;
						}
						--z;
					}
				}
			}
			return (ans + target);
		}
};

int main(int argc, char *args[]) {
	vector<int> nums{-1, 2, 1, -4};
	int target = 1;

	cout << Solution::threeSumClosest(nums, target) << endl;

	return 0;
}
