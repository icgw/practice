/* Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example:
 *   Input: [3, 30, 34, 5, 9]
 *  Output: "9534330"
 *
 * Note: The result may be very large, so you need to return a string instead of
 *       an integer.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static string largestNumber(vector<int>& nums){
			if (nums.size() < 1) return "0";
			sort(nums.begin(), nums.end(), [](int a, int b){
					return to_string(a) + to_string(b) > to_string(b) + to_string(a);
				});
			string ans;
			for (auto& x : nums){
				ans += to_string(x);
			}
			return ans[0] == '0' ? "0" : ans;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {3, 30, 34, 5, 9};
	cout << Solution::largestNumber(nums) << endl;
	return 0;
}
