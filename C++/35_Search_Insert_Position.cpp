/* Given a sorted array and target value, return the index if the target is 
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 * Input: [1, 3, 5, 6], 5
 * Output: 2
 *
 * Example 2:
 * Inpute: [1, 3, 5, 6], 2
 * Output: 1
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int searchInsert(vector<int>& nums, int target){
			if (nums.size() == 0)
				return 0;

			int l = 0, r = nums.size() - 1;

			if (target < nums[0])
				return 0;

			if (target > nums[r])
				return r + 1;

			int ans = 0;
			while (l <= r){
				ans = (l + r + 1) / 2;
				if (nums[ans] > target){
					r = ans - 1;
				}
				else if (nums[ans] < target){
					l = ans + 1;
				}
				else {
					return ans;
				}
			}

			return (l + r + 1) / 2;
		}
};

int main(int argc, char* args[]){
	int a[4] = {1, 3, 5, 6};
	vector<int> aa(a, a + 4);
	int a_t = 5;

	int b[2] = {1, 3};
	vector<int> bb(b, b + 2);

	cout << Solution::searchInsert(aa, a_t) << endl;
	cout << Solution::searchInsert(aa, 2) << endl;
	cout << Solution::searchInsert(aa, 7) << endl;
	cout << Solution::searchInsert(aa, 0) << endl;
	cout << Solution::searchInsert(bb, 2) << endl;

	return 0;
}
