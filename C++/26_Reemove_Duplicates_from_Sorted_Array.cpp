/* Given a sorted array nums, remove the duplicates in-place such that each ele-
 * ment appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		static int removeDuplicates(vector<int>& nums) {
			int cur_id = 0, del_n = 0;
			int len = nums.size();
			int tmp, i;
			while (cur_id < len - 1){
				tmp = nums[cur_id];
				i = cur_id + 1;
				if (nums[i] == tmp){
					nums.erase(nums.begin() + i);
					--len;
				} else {
					++cur_id;
				}
			}
			return len;
		}
};

int main(int argc, char* args[]){
	int a[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	vector<int> nums(a, a + 9);

	int s = Solution::removeDuplicates(nums);
	for (int i = 0; i < s; ++i){
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
