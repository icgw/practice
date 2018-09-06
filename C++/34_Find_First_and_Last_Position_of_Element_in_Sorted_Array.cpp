/* Given an array of integers `nums` sorted in ascending order, find the start-
 * ing and ending position of given `target` value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return `[-1, -1]`.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static vector<int> searchRange(vector<int>& nums, int target){
			vector<int> ans;
			int size = nums.size();
			if (size == 0){
				ans.push_back(-1);
				ans.push_back(-1);
				return ans;
			}

			if (size == 1){
				if (nums[0] == target){
					ans.push_back(0);
					ans.push_back(0);
				} else {
					ans.push_back(-1);
					ans.push_back(-1);
				}
				return ans;
			}
			
			int l = 0, r = size - 1;
			int left, right;
			int m;
			while (l < r){
				m = (l + r) / 2;
				if (nums[m] >= target)
					r = m;
				else
					l = m + 1;
			}
			left = (nums[l] == target) ? l : -1;

			l = left, r = size - 1;
			while (l < r){
				m = (l + r + 1) / 2;
				if (nums[m] <= target)
					l = m;
				else
					r = m - 1;
			}
			right = (nums[r] == target) ? r : -1;
			ans.push_back(left);
			ans.push_back(right);

			return ans;
		}
};

int main(int argc, char* args[]){
	int a[6] = {5, 7, 7, 8, 8, 10};
	vector<int> aa(a, a + 6);

	int b[6] = {5, 7, 7, 8, 8, 10};
	vector<int> bb(b, b + 6);

	vector<int> a_ans = Solution::searchRange(aa, 8);
	cout << a_ans[0] << ", " << a_ans[1] << endl;

	vector<int> b_ans = Solution::searchRange(bb, 6);
	cout << b_ans[0] << ", " << b_ans[1] << endl;

	return 0;
}
