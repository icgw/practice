/* Given an array of size n, find the majority element. The majority element is 
 * the element that appears more than [_ n/2 _] times.
 *
 * You may assume that the array is non-empty and the majority element always 
 * exist in the array.
 *
 * Example:
 * 	 Input: [2, 2, 1, 1, 1, 2, 2]
 * 	Output: 2
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		/* static int majorityElement(vector<int>& nums){
			unordered_map<int, int> m;
			int sz = nums.size(), n;
			if (sz < 1) return 0;
			n = sz / 2;
			for (int i = 0; i < sz; ++i){
				if (m.find(nums[i]) == m.end()){
					m[nums[i]] = 1;
				} else {
					++(m[nums[i]]);
					if (m[nums[i]] > n) return nums[i];
				}
			}
			return nums[0];
		} */
		static int majorityElement(vector<int>& nums){
			unordered_map<int, int> m;
			int sz = nums.size(), n, ans;
			n = sz / 2;
			for (int i = 0; i < sz; ++i){
				++m[nums[i]];
			}
			for (auto& x : m){
				if (x.second > n){
					ans = x.first;
					break;
				}
			}
			return ans;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {2, 2, 1, 1, 1, 2, 2};
	cout << Solution::majorityElement(nums) << endl;
	return 0;
}
