/* Given a non-empty array of integers, every element appears three times except
 * for one, which appears exactly once. Find that single one.
 *
 * Note:
 * 	Your algorithm should have a linear runtime complexity. Could you implement 
 * 	it without using extra memory?
 *
 * Example:
 * 	Input:  [0, 1, 0, 1, 0, 1, 99]
 * 	Output: 99
 */ 
#include <iostream>
#include <vector>

using namespace std;

auto const x = [](){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

class Solution {
	public:
		static int singleNumber(vector<int>& nums){
			int one = 0, two = 0, three = 0;
			for (auto& x : nums){
				two |= (one & x);
				one ^= x;
				three = (one & two);
				one &= ~three;
				two &= ~three;
			}
			return one;
		}
};

int main(int argc, char *argv[]){
	vector<int> nums {0, 1, 0, 1, 0, 1, 99};
	cout << Solution::singleNumber(nums) << endl;
	
	return 0;
}
