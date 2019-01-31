/* Given an integer array `nums`, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int maxSubArray(vector<int>& nums){
			if (nums.size() == 1){
				return nums[0];
			}
			int ans = INT_MIN, sum;
			int n = nums.size();
			for (int i = 0; i < n; ++i){
				sum = 0;
				for (int j = i; j < n; ++j){
					sum += nums[j];
					if (sum > ans){
						ans = sum;
					}
				}
			}
			return ans;
		}

};

int main(int argc, char* args[]){
	int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> aa(a, a + 9);

	cout << Solution::maxSubArray(aa) << endl;

	return 0;
}
