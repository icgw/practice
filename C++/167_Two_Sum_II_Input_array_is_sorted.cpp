/* Given an array of integers that is already sorted in ascending order, find 
 * two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 *
 * Note:
 * 	+ Your returned answers (both index1 and index2) are not zero-based.
 * 	+ You may assume that each input would have exactly one solution and you
 * 	  may not use the same element twice.
 *
 * Example:
 *   Input: numbers = [2, 7, 11, 15], target = 9
 *  Output: [1, 2]
 *  Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		// Bad Idea.
		/* static vector<int> twoSum(vector<int>& numbers, int target){ 
			vector<int> ans;
			int n = numbers.size();
			int r;
			for (int i = 0; i < n; ++i){
				r = target - numbers[i];
				for (int j = i + 1; j < n && numbers[j] <= r; ++j){
					if (numbers[j] == r){
						ans.push_back(i + 1);
						ans.push_back(j + 1);
						return ans;
					}
				}
			}
			return ans;
		} */
		static vector<int> twoSum(vector<int>& numbers, int target){
			int l = 0, r = numbers.size() - 1, sum;
			while (l < r){
				sum = numbers[l] + numbers[r];
				if (sum == target) return {l + 1, r + 1};

				if (sum < target) ++l;
				if (sum > target) --r;
			}
			return {};
		}
};

int main(int argc, char *agrv[]){
	vector<int> nums {2, 7, 11, 15};
	vector<int> ans = Solution::twoSum(nums, 9);
	for (auto &i : ans){
		cout << nums[i - 1] << endl;
	}
	return 0;
}
