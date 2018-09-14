/* Given an array of non-negative integers, you are initially positioned at the 
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that 
 * position.
 *
 * Determine if you are able to reach the last index.
 * Example:
 * 	Input: [2, 3, 1, 1, 4]
 * 	Outpu: true
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool canJump(vector<int>& nums){
			if (nums.size() == 1)
				return true;

			return DFS(nums, 0, nums[0]);
		}

		static bool DFS(vector<int>& nums, int i, int pos){
			if (nums[i] == 0){
				return false;
			}

			for (int j = i; j <= pos; ++j){
				if (j + nums[j] >= nums.size() - 1)
					return true;

				if (j + nums[j] > pos && DFS(nums, j, j + nums[j])){
					return true;
				}
			}
			return false;
		}
};

int main(int argc, char* args[]){
	int a[5] = {2, 3, 1, 1, 4};
	vector<int> aa(a, a + 5);
	cout << Solution::canJump(aa) << endl;

	int b[5] = {3, 2, 1, 0, 4};
	vector<int> bb(b, b + 5);
	cout << Solution::canJump(bb) << endl;

	return 0;
}

