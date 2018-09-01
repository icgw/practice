/* Given an array nums and a value val, remove all instances of that value
 * in-place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int removeElement(vector<int>& nums, int val) {
			int length = nums.size();
			if (length == 0)
				return 0;

			int num = 0;
			for (int i = 0; i < length; ++i){
				if (nums[i] != val){
					nums[num++] = nums[i];
				}
			}
			return num;
		}
};

int main(int argc, char* args[]){
	int a[8] = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 2;
	vector<int> nums(a, a + 7);

	int s = Solution::removeElement(nums, val);
	for (int i = 0; i < s; ++i){
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}
