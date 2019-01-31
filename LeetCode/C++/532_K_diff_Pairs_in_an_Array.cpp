/* Given an array of integers and an integer k, you need to find the number of 
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an integer
 * pair (i, j), where i and j are both numbers in the array and their absolute 
 * difference is k.
 *
 * Example:
 *   Input: [1, 3, 1, 5, 4], k = 0
 *  Output: 1
 *  Explanation: There is one 0-diff pair in the array, (1, 1).
 *
 * Note:
 *  1. The pairs (i, j) and (j, i) count as the same pair.
 *  2. The length of the array won't exceed 10,000.
 *  3. All the integers in the given input belong to the range: [-1e7, 1e7].
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		static int findPairs(vector<int>& nums, int k){ // Not Good...
			unordered_map<int, int> m;
			int ans = 0;
			for (auto n : nums) ++m[n];
			if (k == 0){
				for (auto a : m) if (a.second > 1) ++ans;
			} 
			else if (k > 0) {
				for (auto a : m) if (m.count(a.first + k)) ++ans;
			}
			return ans;
		}

		/* static int findPairs(vector<int>& nums, int k){ 
		    // Time Limit Exceeded.
			unordered_map<int, int> m;
			sort(nums.begin(), nums.end());
			int sz = nums.size();
			for (int i = 0; i < sz; ++i){
				if (i != 0 && nums[i] == nums[i - 1]) continue;
				for (int j = i + 1; j < sz; ++j){
					if (j != i + 1 && nums[j] == nums[j - 1]) continue;
					++m[abs(nums[i] - nums[j])];
				}
			}
			return m[k];
		} */
};

int main(int argc, char *argv[]){
	vector<int> nums {3, 1, 4, 1, 5};
	int k = 2;
	cout << Solution::findPairs(nums, k) << endl;
	return 0;
}
