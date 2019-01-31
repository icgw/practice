/* Given a sorted array nums, remove the duplicates in-place such that 
 * duplicates appeared at most twice and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input in-place with O(1) extra memory.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int removeDuplicates(vector<int>& nums){
			int n = nums.size();
			if (n <= 2) return n;

			int i = 1;
			int pre = nums[0];
			bool canSwap = true;
			for (int j = 1; j < n; ++j){
				if (canSwap && nums[i] == pre){
					++i;
					canSwap = false;
					continue;
				}

				if (nums[j] > pre){
					pre = nums[j];
					swap(nums[i], nums[j]);
					++i;
					canSwap = true;
				}
				else if (canSwap && nums[j] == pre){
					swap(nums[i], nums[j]);
					++i;
					canSwap = false;
				}
			}

			return i;
		}
};

int main(int argc, char* args[]){
	vector<int> nums1(9, 0);
	nums1[0] = 0; nums1[1] = 0; 
	nums1[2] = 1; nums1[3] = 1; nums1[4] = 1; nums1[5] = 1;
	nums1[6] = 2;
	nums1[7] = 3; nums1[8] = 3;

	int n = Solution::removeDuplicates(nums1);
	for (int i = 0; i < n; ++i){
		cout << nums1[i] << " ";
	}
	cout << endl;

	return 0;
}
